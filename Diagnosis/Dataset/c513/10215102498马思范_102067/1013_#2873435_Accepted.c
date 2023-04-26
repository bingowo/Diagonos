#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a,int b)
{
    return a ? gcd(b % a, a) : b;
}
int main()
{
    char s[40];
    int cou=0;
    scanf("%s",s);
    int len=strlen(s);
    for(int j=0;j<len;j++)
    {
        if(s[j]!='.')
            cou++;
        else break;
    }
    long long int zheng=0;
    for(int i=0;i<cou;i++)
    {
        if(s[i]=='1')
            zheng=zheng+pow(3,cou-i-1);
        else if(s[i]=='2')
            zheng=zheng-pow(3,cou-i-1);
        else if(s[i]=='0')
            zheng=zheng;
    }
    long long int zi=0;
    long long int mu=1;
    for(int p=cou+1;p<len;p++)
    {
        zi=zi*3;
        if(s[p]=='1')
            zi=zi+1;
        else if(s[p]=='2')
            zi=zi-1;
        mu=mu*3;
    }
    if(zi<0&&zheng>0)
    {
        zheng=zheng-1;
        zi=mu-abs(zi);
    }
    if(zheng<0&&zi>0)
    {
        zheng=zheng+1;
        zi=mu-zi;
    }
    long long int k=gcd(abs(zi),abs(mu));
    if(zi!=0&&mu!=1&&zheng!=0)
        printf("%lld %lld %lld",zheng,zi/k,mu/k);
    else if(zheng==0&&zi!=0&&mu!=1)
        printf("%lld %lld",zi/k,mu/k);
    else
        printf("%lld",zheng);
    return 0;
}