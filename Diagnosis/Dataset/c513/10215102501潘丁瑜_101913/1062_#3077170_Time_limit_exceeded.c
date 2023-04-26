#include <stdio.h>
#include <stdlib.h>

long long int f(long long n)
{
    if(n > 4)
    {
        return (f(n-1)+f(n-2)+f(n-3)+f(n-4));
    }
    else if(n==3)
        return 4;
    else if(n==2)
        return 2;
    else return 1;
}

int main()
{
    int t,i;
    long long int r,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        r=f(n);
        printf("case #%d:\n",i);
        printf("%lld\n",r);
    }
    return 0;
}