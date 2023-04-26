#include<stdio.h>

int GCD(int m,int n)
{
    if(m>n)
    {
        int t=m;
        m=n;
        n=t;
    }
    if(n%m==0) return m;
    else return GCD(m,n%m);
}

int main()
{
    char s[1000];
    scanf("%s",&s);
    unsigned int p=0;
    long long ansA=0,ansB=0, ansC=1;
    for (;p<strlen(s);p++)
    {
        if (s[p]=='.') break;
        ansA = ansA *3;
        if (s[p]=='1') ansA += 1;
        if (s[p]=='2') ansA -= 1;
    }
    p++;
    for (;p<strlen(s);p++)
    {
        ansB =ansB * 3;
        if (s[p]=='2') ansB -= 1;
        if (s[p]=='1') ansB += 1;
        ansC = ansC * 3;
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
