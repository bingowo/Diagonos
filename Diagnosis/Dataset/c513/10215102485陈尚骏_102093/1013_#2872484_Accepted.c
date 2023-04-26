#include <stdio.h>
#include <stdlib.h>
#include<string.h>

long long GCD(long long m,long long n)
{
    return n%m==0?m:GCD(n%m,m);
}

void dealint(char *s)
{
    long long ansA=0;
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        ansA=ansA*3;
        if(s[i]=='1')
            ansA++;
        if(s[i]=='2')
            ansA--;
    }
    printf("%lld",ansA);
}

void dealdouble(char *s)
{
    long long ansA=0,ansB=0,ansC=1;
    int l=strlen(s);
    int d;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='.')
            d=i;}
    for(int i=0;i<d;i++)
        {
            ansA=ansA*3;
            if(s[i]=='1')
                ansA++;
            if(s[i]=='2')
                ansA--;
        }
        for(int j=d+1;j<l;j++)
        {
            ansB=ansB*3;
            ansC=ansC*3;
            if(s[j]=='1')
                ansB++;
            if(s[j]=='2')
                ansB--;
        }
        if(ansB<0&&ansA!=0)
        {
            ansB=ansB+ansC;
            ansA--;
        }
        else if(ansB>0&&ansA<0)
        {
            ansA++;
            ansB=ansC-ansB;
        }
        long long m=ansC/GCD(ansC,ansB);
        long long n=ansB/GCD(ansC,ansB);
        if(m<0)
        {
            m=-m;
            n=-n;
        }
        if(ansA==0)
            printf("%lld %lld",n,m);
        else printf("%lld %lld %lld",ansA,n,m);
    }

int main()
{
    char s[31]={'\0'};
    scanf("%s",&s);
    if(strchr(s,'.')==0) dealint(s);
    else dealdouble(s);
    return 0;
}
