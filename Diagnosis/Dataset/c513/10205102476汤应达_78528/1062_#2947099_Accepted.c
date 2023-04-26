#include<stdio.h>

long long solve(long long a)
{
    long long arr[100];
    arr[0]=1;arr[1]=1;
    arr[2]=2;arr[3]=4;
    for(int i=4;i<=a;i++)
    {arr[i]=arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];}

    return arr[a];
}

int main()
{
    int t;scanf("%d",&t);
    long long a;
    for(int i=0;i<t;i++)
    {
        scanf("%lld",&a);
        printf("case #%d:\n%lld\n",i,solve(a));
    }
    return 0;
}