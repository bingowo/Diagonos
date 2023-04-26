#include<stdio.h>

int f(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    return f(n-1)+f(n-2)+f(n-3);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        printf("%d\n",f(n));
        
    }
    return 0;
}
