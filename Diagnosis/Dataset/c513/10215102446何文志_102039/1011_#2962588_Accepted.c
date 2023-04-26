#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Complex{
    long long a;
    long long b;
}cmplx;

void binaryStringToCmplx(char* s,cmplx* res){
    cmplx base;base.a = 1;base.b = -1;
    long long len = strlen(s);
    for(int i = 0;i<len;i++){
        long long a1 = res->a, b1 = res->b;
        res->a = 0-a1 - b1 + s[i]-'0';
        res->b = a1-b1;
        //printf("resA = %lld, resB = %lld\n",res->a,res->b);
    }
    return;
}

void myPrint(cmplx res){
    long long a1 = res.a;
    long long b1 = res.b;
    if((a1==0)&&(b1==0)){
        printf("0\n");
        return;
    }
    if(a1==0){
        if(b1==1){
            printf("i\n");
            return;
        }
        if(b1==-1){
            printf("-i\n");
            return;
        }
        printf("%lldi\n",b1);
        return;
    }
    else{
        printf("%lld",a1);
        if(b1==0){
            return;
        }
        if(b1==1){
            printf("+i\n");
            return;
        }
        if(b1==-1){
            printf("-i\n");
            return;
        }
        if(b1>0){
            printf("+%lldi\n",b1);
            return;
        }
        printf("%lldi\n",b1);
    }
    //printf("hhh resA = %lld, resB = %lld\n",a1,b1);
    return;
}

void OxtoBinaryString(char* sx,char* s){
    int sxlen = strlen(sx);
    char table[16][5] = {"0000","0001","0010","0011","0100","0101","0110","0111",
                        "1000","1001","1010","1011","1100","1101","1110","1111",};
    for(int i = 2;i<sxlen;i++){
        int index = 0;
        if(isdigit(sx[i])){
            index = sx[i]-'0';
        }
        else if(isalpha(sx[i])){
            index = sx[i]-'A'+10;
        }

        strcat(s,table[index]);
        //printf("%d, %s\n",index,s);
    }

}

void itoBinaryString(long long n,char* binS){
    long long r = 0;
    long long cnt = 0;
    while(n!=0){
        r = n%2;
        n = n/2;
        binS[cnt++] = r+'0';
    }

    for(long long i = 0,j = cnt-1;i<j;i++,j--){
        char tmp = binS[i];
        binS[i] = binS[j];
        binS[j] = tmp;
    }
    //printf("binS = %s\n",binS);
    return;
}

int main()
{
    //long long n = 0;
    //char ns[1000];memset(ns,0,1000*sizeof(char));
    char sx[1000];memset(sx,0,1000*sizeof(char));
    scanf("%s",sx);
    //scanf("%llx",&n);
    char s[1000];memset(s,0,1000*sizeof(char));
    OxtoBinaryString(sx,s);

    cmplx res;res.a = 0;res.b = 0;
    binaryStringToCmplx(s,&res);
    //printf(";;;resA = %lld, resB = %lld\n",res.a,res.b);
    myPrint(res);

    return 0;
}
