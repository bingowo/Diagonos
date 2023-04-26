#include <stdio.h>

int f(int n)
{
    if(n==1)
        return 2;
    if(n==2)
        return 4;
    if(n==3)
        return 7;
    if(n==4)
        return 12;
    return f(n-1)+f(n-1)-f(n-2)+f(n-3);
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        printf("%d\n",f(n));
        scanf("%d",&n);
    }
}
