#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    int v[200];
}BIGINT;

BIGINT arr[500]={1,{1}};//存当n等于下标的时候的情况数

BIGINT init(BIGINT x)
{
    BIGINT y={0,{0}};
    y.cnt=x.cnt;
    for(int i=0;i<x.cnt;i++)
        y.v[i]=x.v[i];
    return y;
}

BIGINT add(BIGINT x,BIGINT y)
{
    BIGINT sum={0,{0}};
    int max=x.cnt>y.cnt?x.cnt:y.cnt;
    int carry=0;
    for(;sum.cnt<max;sum.cnt++)
    {
        int tmp=x.v[sum.cnt]+y.v[sum.cnt]+carry;
        sum.v[sum.cnt]=tmp%10;
        carry=tmp/10;
    }
    if(carry)
        sum.v[sum.cnt++]=carry;
    return sum;
}

BIGINT count(int n)
{
    BIGINT x0={1,{1}};
    if(n==0) return x0;
    BIGINT x1,x2,x3;
    if(arr[n-1].cnt) x1=init(arr[n-1]);
    else x1=count(n-1),arr[n-1]=init(x1);
    if(n>=2)
    {
        if(arr[n-2].cnt) x2=init(arr[n-2]);
        else x2=count(n-2),arr[n-2]=init(x2);
    }
    if(n>=4)
    {
        if(arr[n-4].cnt) x3=init(arr[n-4]);
        else x3=count(n-4),arr[n-4]=init(x3);
    }
    if(n>=4)
        return add(add(x1,x2),x3);
    else if(n>=2)
        return add(x1,x2);
    else
        return x1;
}
int main()
{
    int n=0;
    scanf("%d",&n);
    BIGINT sum=count(n);
    for(int i=sum.cnt-1;i>=0;i--)
        printf("%d",sum.v[i]);
    return 0;
}