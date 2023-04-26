#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long f(int n)
{
    if(n==1||n==2)return 1;
    else return f(n-1)+f(n-2)+f(n-3);
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d",&n);
        long long sum=f(n);
        printf("%lld",sum);
    }
}