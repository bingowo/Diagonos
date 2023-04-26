#include <stdio.h>
#include <stdlib.h>

long long int f(int n)
{
    if(n>4)
        return (f(n-1)+f(n-2)+f(n-3)+f(n-4));
    else
    {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 4;
        if(n==4)
            return 9;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        long long int possibility;
        printf("case #%d:\n",i);
        if(n==1)
            printf("1\n");
        if(n==2)
            printf("2\n");
        if(n==3)
            printf("4\n");
        if(n==4)
            printf("9\n");
        if(n>4)
        {
            possibility=f(n);
            printf("%lld\n",possibility);
        }
    }
}