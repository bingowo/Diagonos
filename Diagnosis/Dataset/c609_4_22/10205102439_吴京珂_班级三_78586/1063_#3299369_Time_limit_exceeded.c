#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long int f(long long int n)
{
    if(n<5) return 1;
    else return f(n-1)+f(n-2)+f(n-3)+f(n-4);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        long long int n;
        scanf("%lld",&n);
        long long int ans=f(n);
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }

    return 0;
}