#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long x=0,y=0;long long k=1;
int val(long long sum,long long n,long long i)
{
    if(sum<n)return 1;
    else
    {
        if(i%4==0)printf("(%lld,%lld)",x,y+n-sum);
        else if(i%4==1)printf("(%lld,%lld)",x-n+sum,y);
        else if(i%4==2)printf("(%lld,%lld)",x,y-n+sum);
        else if(i%4==3)printf("(%lld,%lld)",x+n-sum,y);
        return 0;
    }
}

int main()
{
    long long n,sum=0;scanf("%lld",&n);
    int flag=1;long long i;
    for(i=0;flag==1;i++)
    {
        if(i%4==0)
        {y=y+k;sum+=k;flag=val(sum,n,i);}
        else if(i%4==1)
        {x=x-k;sum+=k;flag=val(sum,n,i);k++;}
        else if(i%4==2)
        {y=y-k;sum+=k;flag=val(sum,n,i);}
        else 
        {x=x+k;sum+=k;flag=val(sum,n,i);k++;}
    }
}