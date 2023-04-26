#include<stdio.h>

long long int f(int i)
{
    if(i == 0)
    {
        return 0;
    }
    if(i == 1)
    {
        return 1;
    }
    if(i == 2)
    {
        return 1;
    }
    return f(i-1)+f(i-2)+f(i-3);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int i;
        scanf("%d",&i);
        printf("%lld\n",f(i));
        
    }
    return 0;
}
