#include<stdio.h>
#include<stdlib.h>


long long f(int n)
{
    long long ans[21];
    ans[1]=2;
    ans[2]=4;
    ans[3]=7;
    ans[4]=12;
    for(int i=5;i<21;i++)
    {
        ans[i]=ans[i-1]*2-ans[i-2]+ans[i-3];
    }
    return ans[n];
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n!=-1)
    {
        printf("%lld\n",f(n));
    }
}
