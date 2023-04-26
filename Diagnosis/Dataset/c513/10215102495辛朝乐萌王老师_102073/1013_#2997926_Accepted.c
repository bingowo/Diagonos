#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int GCD(int m,int n)
{
    int t,r;
    if(m<n){
        t=m;
        m=n;
        n=t;
    }
    while ((m%n)!=0) {
        r=m%n;
        m=n;
        n=r;
    }
    return n;
}

int main()
{
    char s[150];
    scanf("%s",s);
    char *p=s;
    long long ansA=0;
    long long ansB=0,ansC=1;
    scanf("%s",s);
    while (*p!='.'&&*p) {
        ansA=ansA*3;
        if (*p=='1') {
            ansA+=1;
        }
        if (*p=='2') {
            ansA-=1;
        }
        p++;
    }
    if (*p) {
        p++;
    }
    while (*p) {
        ansB=ansB*3;
        ansC=ansC*3;
        if (*p=='1') {
            ansB+=1;
        }
        if (*p=='2') {
            ansB-=1;
        }
        p++;
    }
    if (ansB==0) {
        printf("%lld",ansA);
    }
    else if(ansB>0){
        if (ansA<0) {
            ansA++;
            ansB=ansC-ansB;
        }
        if(ansA==0){
            printf("%lld %lld",ansB,ansC);
        }
        else{
            printf("%lld %lld %lld",ansA,ansB,ansC);
        }
    }
    else if(ansB<0){
        if (ansA>0) {
            ansA--;
            ansB=ansC+ansB;
        }
        if(ansA==0){
            printf("%lld %lld",ansB,ansC);
        }
        else{
            printf("%lld %lld %lld",ansA,ansB,ansC);
        }
    }
    return 0;
}
