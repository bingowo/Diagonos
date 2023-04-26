#include<stdio.h>
long long N2T(long long x)
{
    long long rt=0,w=1;
    while(x>0)
    {
        rt+=x%10*w;
        x/=10;
        w*=9;
    }
    return rt;
}
int f(long long x)
{
    int rt=0,t,k,flag=0;
    for(long long i=x-x%10+1;i<=x;i++)
    {
        if(i%9==0)  continue;
        t=i;
        flag=1;
        while(t>0)
        {
            if(t%10==9)  flag=0;
            t/=10;
        }
        if(flag==1)
        {
            rt++;
        }
    }
    return rt;
}
long long g(long long x)
{
    return N2T(x-x%10)*8/9+f(x);
}
int main()
{
    long long a,b,ans;
    scanf("%lld%lld",&a,&b);
    ans=g(b)-g(a)+1;
    printf("%lld",ans);
    return 0;
}