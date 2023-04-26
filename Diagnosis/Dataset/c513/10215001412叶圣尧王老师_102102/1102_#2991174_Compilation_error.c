#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long x=0,y=0;long k=2;

int val1(long long sum,long long n)
{
    sum-=k;
    if(sum+k/2>=n)printf("(%lld,%lld)",x,y+n-sum);
    else printf("(%lld,%lld)",x-n+sum+k/2,y+k/2);
    return 0;
}

int val2(long long sum,long long n)
{
    sum-=k;
    if(sum+k/2>=n)printf("(%lld,%lld)",x,y-n+sum);
    else printf("(%lld,%lld)",x+n-sum-k/2,y-k/2);
    return 0;
}
int main()
{
    long long n,sum=0;scanf("%lld",&n);
    int flag=1；long long i;
    for(i=0;flag==1;i++)
    {
        if(i%2==0)
        {
            sum+=k;
            if(sum>=n)flag=val1(sum,n);
            x=x-k/2;y=y+k/2;
            k+=2;
        }
        else
        {
            sum+=k;
            if(sum>=n)flag=val2(sum,n);
            x=x+k/2;y=y-k/2;
            k+=2;
        }
    }
}