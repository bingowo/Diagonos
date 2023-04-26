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
    unsigned int p=0;
    char s[1000];
    long long ansA=0;
    long long ansB=0,ansC=1;
    scanf("%s",s);
    int len=strlen(s);
    for (; p<len; p++) {
        if(s[p]=='.') break;
        ansA*=3;
        if (s[p]=='1') {
            ansA+=1;
        }
        if (s[p]=='2') {
            ansA-=1;
        }
    }
    for (; p<len; p++) {
        ansB*=3;
        if (s[p]=='1') {
            ansA+=1;
        }
        if (s[p]=='2') {
            ansA-=1;
        }
        ansC*=3;
        if (ansA>0&&ansB<0) {
            ansA--;
            ansB=ansB+ansC;
        }
        else if(ansA<0&&ansB>0){
            ansA++;
            ansB=ansC-ansB;
            if (ansA==1) {
                ansB=-ansB;
            }
        }
    }
    long long t=GCD(abs(ansB), abs(ansC));
    if (ansB==0) printf("%lld\n",ansA);
    else
    { if (ansA!=0) printf("%lld ",ansA);
      else printf("%lld %lld\n",ansB/t,ansC/t);
    }
    return 0;
}
