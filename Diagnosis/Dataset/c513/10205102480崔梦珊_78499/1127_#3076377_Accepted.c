#include<stdio.h>
#include<string.h>
#include<math.h>
long long bei(long long a,long long b)
{
    long long temp=a*b;
    while(a%b!=0)
    {
        long long p=a;
        a=b;
        b=p%b;
    }
    //printf("bei:%lld\n",temp/b);
    return temp/b;
}

long long yue(long long a,long long b)
{
    while(a%b!=0)
    {
        long long p=a;
        a=b;
        b=p%b;
    }
    return b;
}

int main()
{
    int n;
    scanf("%d",&n);
    long long zi,mu;
    for(int i=0;i<n;i++)
    {
        long long fenzi,fenmu;
        scanf("%lld/%lld",&fenzi,&fenmu);
        if(i==0)
        {
            zi=fenzi;
            mu=fenmu;
        }
        else
        {
            if(fenmu==mu)
            {
                zi+=fenzi;
            }
            else
            {
                long long temp=0;
                if(fenmu>mu)
                {
                    temp=bei(fenmu,mu);
                }
                else
                {
                    temp=bei(mu,fenmu);
                }
                long long temp1=temp/fenmu*fenzi;
                long long temp2=temp/mu*zi;
                //printf("%lld %lld\n",temp1,temp2);
                mu=temp;
                //printf("%lld\n",mu);
                zi=temp1+temp2;
            }
        }
        if(zi>=mu)
        {
            long long te=yue(zi,mu);
            zi=zi/te;
            mu=mu/te;
        }
        if(fenzi>fenmu)
        {
            long long te=yue(mu,zi);
            zi=zi/te;
            mu=mu/te;
        }
        //printf("%lld/%lld\n",zi,mu);

    }
    printf("%lld/%lld",zi,mu);
    return 0;
}
