#include<stdio.h>

long long f(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else if(n == 3)
    {
        return 3;
    }
    else if(n == 4)
    {
        return 8;
    }
    else
    {
        return f(n-1)+f(n-2)+f(n-3)+f(n-4);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",f(n));
    }
    return 0;
}

