#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld",&n);
    long long i;
    if(n<=6)
        i=-1;
    else
    {
        for(i=0;4*i*i+10*i+6<n;i++);
        i--;
    }
    long long sum=0;
    long long x=0,y=0;
    if(i==-1)
        sum=n;
    else
    {
        sum=n-4*i*i-10*i-6;
        x=i+1;
        y=-i-1;
    }
    long long l1=2*x+1,l2=2*x+2;
    if(sum<=l1)
        y=y+sum;
    else if(sum<=2*l1)
    {
        y=y+l1;
        x=x-(sum-l1);
    }
    else if(sum<=2*l1+l2)
    {
        x=x-l1;
        y=y+l1-(sum-2*l1);
    }
    else
    {
        y=y+l1-l2;
        x=x-l1+(sum-2*l1-l2);
    }
    printf("(%lld,%lld)\n",x,y);
}
//还是注意细节吧
//llu不能是负数
//算法的优化很重要
//重要的是找出题目的特点
//着重进行突破

