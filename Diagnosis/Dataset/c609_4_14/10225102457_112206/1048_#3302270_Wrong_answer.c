#define MAX_LEN 200
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
//add i1 and i2, return result

int main(void){
    char in[MAX_LEN];
    scanf("%s",in);

    if(strcmp(in,"0") == 0){putchar('0'); return 0;}
    else if(strcmp(in,"1") == 0 || strcmp(in,"2") == 0) {putchar('1'); return 0;}

    int inp = atoi(in);
    NUM F1,F2;
    F1 = write("1");
    F2 = write("1");

    for(int v = 2; v < inp; v++){
        NUM temp = F2;
        F2 = plu(&F1,&F2);
        F1 = temp;
    }

    printf("%s",F2.num);
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

    for(int v = 0; v < i1->flen || v < i2->flen; v++){
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
    }

    for(int v = 0; v < i1->ilen || v < i2->ilen; v++){
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
    }
    if(carry != 0){
        re.i[re.ilen] = carry;
        re.ilen++;
    }

    for(int v = 0; v < re.ilen; v++){
        re.num[v] = re.i[re.ilen - v -1] + '0';
        re.num[v+1] = '\0';
    }

    while(re.flen > 0 && re.fl[re.flen-1] == 0) re.flen--;
    if(re.flen != 0) re.num[re.ilen] = '.';

    for(int v = re.ilen + 1; v < re.ilen+re.flen+1; v++){
        re.num[v] = re.fl[re.flen - v + re.ilen] + '0';
        re.num[v+1] = '\0';
    }

    return re;
}

NUM write(const char *in){
    NUM re;
    const char* head = in;

    re.flen = re.ilen = 0;
    for(int v = 0; v < MAX_LEN; v++){
        re.fl[v] = 0;
        re.i[v] = 0;
    }
    strcpy(re.num,in);//initialize

    for(; *in != '.' && *in != '\0'; in++){
        re.ilen++;
    }

    if(*in == '.') in++;
    while(*in != '\0'){in++; re.flen++;}

    for(int v = 0; v < re.ilen; v++){
        re.i[v] = head[re.ilen - 1 - v] - '0';
    }
    for(int v = 0; v < re.flen; v++){
        re.fl[v] = head[re.ilen + re.flen - v] - '0';
    }

    return re;
}
