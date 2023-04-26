#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define min(a,b) ( ((a)>(b)) ? (b):(a) )

int GCD(int m,int n)
{
    int x;
    if(m==n) return m;
    else if(m>n) {
        x=m%n;
        if(x!=0) {m=x;return GCD(n,x);}
        else return min(m,n);
    }
    else if(m<n) {
        x=n%m;
        if(x!=0) {n=x;return GCD(m,x);}
        else return min(m,n);
    }
}
int main()
{
    char s[30];
    scanf("%s",&s);
    unsigned p=0;
    long long ansA=0,ansB=0,ansC=1;
    for(;p<strlen(s);p++)
    {
        if(s[p]=='.') break;
        ansA*=3;
        if(s[p]=='1')
            ansA+=1;
        if(s[p]=='2')
            ansA-=1;
    }
    p++;
    for(;p<strlen(s);p++)
    {
        ansB*=3;
        if(s[p]=='1')
            ansB+=1;
        if(s[p]=='2')
            ansB-=1;
        ansC*=3;
    }
    if(ansA>0&&ansB<0)
    {
        ansA--;
        ansB=ansB+ansC;
    }
    else{
        if(ansA<0&&ansB>0)
        {
            ansA++;
            ansB=ansC-ansB;
        }
        if(ansA==0)
        {
            ansB=-ansB;
        }
    }
    long long t=GCD(abs(ansB),abs(ansC));
    if (ansB==0) printf("%lld\n",ansA);
    else
    {
    if (ansA!=0) printf("%lld ",ansA);
    printf("%lld %lld\n",ansB/t,ansC/t);
    }
    return 0;
}
