#include<stdio.h>

long long int f(long long int j)
{
    if(j == 0)
    {
        return 0;
    }
    if(j == 1)
    {
        return 1;
    }
    if(j == 2)
    {
        return 1;
    }
    return f(j-1)+f(j-2)+f(j-3);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        long long int j;
        scanf("%lld",&j);
        printf("%lld\n",f(j));

    }
    return 0;
}
