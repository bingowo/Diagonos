#include <stdio.h>
#include <stdlib.h>

long long int f(int n)
{
    if(n > 2)
    {
        return (2*f(n-1));
    }
    else if(n==2)
        return 2;
    else
        return 1;
}

int main()
{
    int t,i,n;
    long long int r;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        r=f(n);
        printf("case #%d:\n",i);
        printf("%lld\n",r);
    }
    return 0;
}