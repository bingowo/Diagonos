#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long x=0,y=0;long long k=2;

int val1(long long sum)
{
    sum-=k;
    if(sum+k/2>=n)printf("(%lld,%lld)",x,y+n-sum);
    else printf("(%lld,%lld)",x-n+sum+k/2,y+k/2);
    return 0;
}

int val2(long long sum)
{
    sum-=k;
    if(sum+k/2>=n)printf("(%lld,%lld)",x,y-n+sum);
    else printf("(%lld,%lld)",x+n-sum-k/2,y-k/2);
    return 0;
}
int main()
{
    long long n,sum=0;scanf("%lld",&n);
    int flag=1;long long i;
    for(i=0;flag==1;i++)
    {
        if(i%2==0)
        {
            sum+=k;
            if(sum>=n)flag=val1(sum,i);
            x=x-k;y=y+k;
            k+=2;
        }
        else
        {
            sum+=k;
            if(sum>=n)flag=val2(sum,i);
            x=x+k;y=y-k;
            k+=2;
        }
    }
}