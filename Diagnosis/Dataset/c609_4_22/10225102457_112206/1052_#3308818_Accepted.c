#define MAX 1003
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int ilen;
    int *i;
}NUM;

void prime(int *n){
    int *w = n;
    for(int i = 2; i < MAX; i++){
        int isprime = 1;
        for(int v = 2; v*v <= i; v++){
            if(i % v == 0){
                isprime = 0;
                break;
            }
        }

        if(isprime){
            *w = i;
            w++;
        }
    }
}

NUM write(const char *in){//reverse integer
    NUM re;
    re.i = (int*)malloc(MAX * sizeof(int) + 1);
    const char* head = in;
    re.ilen = 0;
    for(int v = 0; v < MAX; v++)
        re.i[v] = 0;

    for(;*in != '\0'; in++) re.ilen++;//ilen
    const char *point = in-1;
    for(int v = 0; point >= head; v++,point--) re.i[v] = *point - '0';//write i
    
    while(re.ilen > 1 && re.i[re.ilen-1] == 0) re.ilen--;//del 0 

    return re;
}

void Print(const NUM *in){
	if(in->ilen == 0) putchar('0');//print int
	for(int v = in->ilen-1; v >= 0; v--) printf("%d",in->i[v]);
}

NUM plu(const NUM *i1, const NUM* i2){
    NUM re;
    re.i = (int*)malloc(MAX* sizeof(int) + 1);
    re.ilen = 0;
    for(int v = 0; v < MAX; v++){
        re.i[v] = 0;
    }//initialize
	
	int carry = 0;

    for(int v = 0; v < i1->ilen || v < i2->ilen; v++){//integer
        re.i[v] = i1->i[v] + i2->i[v] + carry;
        if(re.i[v] > 9){
            carry = re.i[v] / 10;
            re.i[v] %= 10;
        }
        else{
            carry = 0;
        }

        re.ilen++;
        if(re.ilen > MAX) fprintf(stderr,"Plu error! Overflow in integer!\n");
    }
    if(carry != 0){//deal with integer overflow
        re.i[re.ilen] = carry;
        re.ilen++;
        if(re.ilen > MAX) fprintf(stderr,"Plu error! Overflow in integer!\n");
    }
    
    while(re.ilen > 1 && re.i[re.ilen-1] == 0) re.ilen--;//del 0 

    return re;
}

NUM multi(const NUM *i1, const NUM* i2){
    NUM re;

    re.i = (int*)malloc(2 * MAX * sizeof(int) + 1);
    re.ilen = 0;
    for(int v = 0; v < 2*MAX+1; v++) re.i[v] = 0;//initialize
	
	int carry = 0;

    for(int t = 0; t < i1->ilen; t++){
        int j = t;
        for(int v = 0; v < i2->ilen; v++,j++){//integer
            re.i[j] += ((i1->i[t] * i2->i[v]) + carry);
            if(re.i[j] > 9){
                carry = re.i[j] / 10;
                re.i[j] %= 10;
            }
            else{
                carry = 0;
            }
        }

        re.ilen = j;
        if(carry != 0){//deal with integer overflow
            re.i[j] += carry;
            re.ilen++;
            carry = 0;
            if(re.ilen > 2*MAX) fprintf(stderr,"Multi error! Overflow in integer!\n");
        }
    }
    
    while(re.ilen > 1 && re.i[re.ilen-1] == 0) re.ilen--;//del 0 

    return re;
}

int main(void)
{
    int len,num[26];
    scanf("%d",&num[0]);
    len = 1;
    while(getchar() != '\n'){
        scanf("%d",&num[len]);
        len++;
    }

    int p[MAX / 2];
    prime(p);
    NUM out = write("0");
    NUM n = write("1");

    int tr = 0;
    for(int i = len-1; i >= 0; i--){
        char temp[10];
        sprintf(temp,"%d",num[i]);
        NUM e = write(temp);
        e = multi(&n,&e);
        out = plu(&out,&e);
        free(e.i);

        char str[10];
        sprintf(str,"%d",p[tr++]);
        e = write(str);
        n = multi(&n,&e);
        free(e.i);
    }
    free(n.i);

    Print(&out);
    free(out.i);
    return 0;
}