#include <stdio.h>
#include <stdlib.h>
#define N 10007
long long int f[1000001];
void init()
{
    for(long long int i=0;i<1000001;i++)
    {
        if(!i||i==1) f[i]=1;
        else f[i]=f[i-1]*i%N;
    }
}
long long int qpow(long long int a,long long int n)
{
    long long int ans=1;
    while(n)
    {
        if(n&1) ans=ans*a%N;
        a=a*a%N;
        n>>=1;
    }
    return ans;
}

int main()
{
    init();
    long long int t,a,b,k,n,m;;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld %lld %lld %lld %lld",&a,&b,&k,&n,&m);
        printf("case #%d:\n",i);
        long long int result=qpow(a,n)*qpow(b,m)%N;
        long long int result2=f[k]*qpow(f[m]*f[k-m]%N,N-2)%N;
        result=result*result2%N;
        printf("%lld\n",result);
    }
    return 0;
}

