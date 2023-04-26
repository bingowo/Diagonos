#define MAX_LEN 505
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int ilen;
    int i[MAX_LEN];
    int flen;
    int fl[MAX_LEN];
    char num[MAX_LEN];
}NUM;

NUM write(const char *in);
//turn a str into NUM;

NUM plu(const NUM *i1, const NUM* i2);
//return result of i1 + i2

int main(void){
    char in[MAX_LEN], in2[MAX_LEN];
    scanf("%s%s",in,in2);
    NUM in1 = *(NUM*)malloc(sizeof(NUM)+1);
    in1 = write(in);
    NUM in21 = *(NUM*)malloc(sizeof(NUM)+1);
    in21 = write(in2);
    NUM out = plu(&in1,&in21);

    int len;
    scanf("%d",&len);

    if(out.fl[len] > 5){
        char temp[MAX_LEN];
        temp[0] = '.';
        for(int v = 1; v < len; v++){
            temp[v] = '0';
        }
        temp[len] = '1';
        temp[len+1] = '\0';
        NUM tem = write(temp);
        printf("%s\n",temp);
        out = plu(&out,&tem);
    }
    for(int v = out.ilen-1; v >= 0; v--){
        printf("%d",out.i[v]);
    }
    if(out.ilen == 0) putchar('0');
    if(len != 0) putchar('.');
    for(int v = 0; v < len; v++){
        printf("%d",out.fl[v]);
    }
    return 0;
}


NUM plu(const NUM *i1, const NUM* i2){
    NUM re;
    re.flen = re.ilen = 0;
    for(int v = 0; v < MAX_LEN; v++){
        re.fl[v] = 0;
        re.i[v] = 0;
    }
    memset(re.num,0,MAX_LEN);//initialize

    int carry = 0;

    int v = i1->flen;//deal with flen diff
    if(i1->flen != i2->flen){
        if(i1->flen > i2->flen){
            for(int v = i1->flen-1; v >= i2->flen; v--){
                re.fl[v] = i1->fl[v];
                re.flen++;
            }
            v = i2->flen;
        }

        else{
            for(int v = i2->flen-1; v >= i1->flen; v--){
                re.fl[v] = i2->fl[v];
                re.flen++;
            }
            v = i1->flen;
        }
    }

    for(; v >= 0; v--){//float first
        int temp = i1->fl[v] + i2->fl[v] + carry;
        if(temp > 9){
            carry = temp / 10;
            temp %= 10;
            re.fl[v] = temp;
            re.flen++;
        }
        else{
            carry = 0;
            re.fl[v] = temp;
            re.flen++;
        }
        if(re.flen > MAX_LEN) printf("Overflow in float!\n");
    }

    for(v = 0; v < i1->ilen || v < i2->ilen; v++){//integer
        int temp = i1->i[v] + i2->i[v] + carry;
        if(temp > 9){
            carry = temp / 10;
            temp %= 10;
            re.i[v] = temp;
            re.ilen++;
        }
        else{
            carry = 0;
            re.i[v] = temp;
            re.ilen++;
        }
        if(re.ilen > MAX_LEN) printf("Overflow in integer!\n");
    }
    if(carry != 0){//deal with integer overflow
        re.i[re.ilen] = carry;
        re.ilen++;
        if(re.ilen > MAX_LEN) printf("Overflow in integer!\n");
    }

    for(v = 0; v < re.ilen; v++){//write to num
        re.num[v] = re.i[re.ilen - v -1] + '0';
        re.num[v+1] = '\0';
    }

    while(re.flen > 0 && re.fl[re.flen-1] == 0) re.flen--;//deal with '.'
    if(re.flen != 0) re.num[re.ilen] = '.';

    for(v = re.ilen + 1; v < re.ilen+re.flen+1; v++){//continue write
        re.num[v] = re.fl[v - re.ilen - 1] + '0';
        re.num[v+1] = '\0';
    }

    return re;
}

NUM write(const char *in){//reverse integer, not float!
    NUM re;
    const char* head = in;

    re.flen = re.ilen = 0;
    for(int v = 0; v < MAX_LEN; v++){
        re.fl[v] = 0;
        re.i[v] = 0;
    }
    strncpy(re.num,in,MAX_LEN);//initialize

    for(; *in != '.' && *in != '\0'; in++){
        re.ilen++;
    }

    const char *point = in-1;//deal with '.'
    if(*in == '.') in++;

    for(int v = 0; *in != '\0'; v++,in++){
        re.fl[v] = *in - '0';
        re.flen++;
    }

    for(int v = 0; point >= head; v++,point--){
        re.i[v] = *point - '0';
    }

    return re;
}