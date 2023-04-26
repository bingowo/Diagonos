#include <stdio.h>
#include <stdlib.h>
long long zh(long long a)
{
    long long m=0;
    if(a<9){return a;}
    else
    {
        m=zh(a/10)*9+a%10;
        return m;
    }
}
long long fz(long long a)
{
    long long m=0,n=0;
    n=a%10;
    for(m=a-n;m<=a;m++)
    {
        char s[50]={0};
        sprintf(s,"%lld",m);
        if(m%9==0 || strchr(s,'9')!=0)n--;
    }
    return n+8*zh(a-a%10)/9;
}
int main()
{
   long long a,b;
   scanf("%lld %lld",&a,&b);
   printf("%lld",fz(b)-fz(a)+1);
    return 0;
}
