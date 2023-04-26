#include <stdio.h>
#include <stdlib.h>

typedef struct Complex{
    long long a;
    long long b;
}cmplx;

void binaryStringToCmplx(char* s,cmplx* res){
    cmplx base;base.a = 1;base.b = -1;
    long long len = strlen(s);
    for(int i = 0;i<len;i++){
        long long a1 = res->a, b1 = res->b;
        res->a = -1*a1 - b1 + s[i]-'0';
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
    long long n = 0;
    scanf("%x",&n);
    char s[100000];memset(s,0,100000*sizeof(char));
    itoBinaryString(n,s);
    cmplx res;res.a = 0;res.b = 0;
    binaryStringToCmplx(s,&res);
    myPrint(res);

    return 0;
}
