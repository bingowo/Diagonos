#define MAX_LEN 503
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	short sgn;
    int ilen;
    int *i;
    int flen;
    int *fl;
}NUM;

NUM plu(const NUM *i1, const NUM* i2){
    NUM re;
    re.sgn = 0;
    re.fl = (int*)malloc(MAX_LEN * sizeof(int) + 1);
    re.i = (int*)malloc(MAX_LEN * sizeof(int) + 1);
    re.flen = re.ilen = 0;
    for(int v = 0; v < MAX_LEN; v++){
        re.fl[v] = 0;
        re.i[v] = 0;
    }//initialize
	
	int carry = 0;
    int v = i1->flen;//deal with flen diff
    if(i1->flen < i2->flen) v = i2->flen;

    for(; v >= 0; v--){//float first
        re.fl[v] = i1->fl[v] + i2->fl[v] + carry;
        if(re.fl[v] > 9){
            carry = re.fl[v] / 10;
            re.fl[v] %= 10;
        }
        else{
            carry = 0;
        }

        re.flen++;
        if(re.flen > MAX_LEN) printf("Overflow in float!\n");
    }

    for(v = 0; v < i1->ilen || v < i2->ilen; v++){//integer
        re.i[v] = i1->i[v] + i2->i[v] + carry;
        if(re.i[v] > 9){
            carry = re.i[v] / 10;
            re.i[v] %= 10;
        }
        else{
            carry = 0;
        }

        re.ilen++;
        if(re.ilen > MAX_LEN) printf("Overflow in integer!\n");
    }
    if(carry != 0){//deal with integer overflow
        re.i[re.ilen] = carry;
        re.ilen++;
        if(re.ilen > MAX_LEN) printf("Overflow in integer!\n");
    }
    
    while(re.ilen > 1 && re.i[re.ilen-1] == 0) re.ilen--;//del 0 
    while(re.flen > 1 && re.fl[re.flen-1] == 0) re.flen--;//del 0

    return re;
}

NUM write(const char *in){//reverse integer, not float!
    NUM re;
    re.fl = (int*)malloc(MAX_LEN * sizeof(int) + 1);
    re.i = (int*)malloc(MAX_LEN * sizeof(int) + 1);
    const char* head = in;
    re.sgn = 0;//default positive
    re.flen = re.ilen = 0;
    for(int v = 0; v < MAX_LEN; v++){
        re.fl[v] = 0;
        re.i[v] = 0;
    }//initialize

	if(*in == '-' || *in == '+'){
		if(*in == '-') re.sgn = 1;//negative
		in++,head++;
	}
    for(; *in != '.' && *in != '\0'; in++) re.ilen++;//ilen
    const char *point = in-1;
    for(int v = 0; point >= head; v++,point--) re.i[v] = *point - '0';//write i

    if(*in == '.') { 
		in++;//deal with '.'
		if(*in == '\0') re.flen++;
	}
    for(int v = 0; *in != '\0'; v++,in++){//write flen and fl
        re.fl[v] = *in - '0';
        re.flen++;
    }
    
    while(re.ilen > 1 && re.i[re.ilen-1] == 0) re.ilen--;//del 0 
    while(re.flen > 1 && re.fl[re.flen-1] == 0) re.flen--;//del 0

    return re;
}

void Print(NUM *in,int len){
	if(in->sgn == 1) putchar('-');

    if(in->fl[len] >= 5 && len < in->flen){
        char temp[len+2];
        temp[0] = '.';
        for(int v = 1; v < len; v++){
            temp[v] = '0';
        }
        temp[len] = '1';
        temp[len+1] = '\0';
        NUM te = write(temp);
        *in = plu(&te,in);
        free(te.fl);
        free(te.i);
    }
	
	if(in->ilen == 0) putchar('0');//print int
	for(int v = in->ilen-1; v >= 0; v--) printf("%d",in->i[v]);
	
	if(in->flen != 0) putchar('.');//print float
	for(int v = 0; v < len; v++) printf("%d",in->fl[v]);
}

int main(void){
	char in[MAX_LEN];
	char in2[MAX_LEN];
    int len;
	scanf("%s%s%d",in,in2,&len);

	NUM out = write(in);
	NUM temp = write(in2);
	out = plu(&out,&temp);
    free(temp.fl);
    free(temp.i);

	Print(&out,len);

    free(out.fl);
    free(out.i);
	return 0;
}