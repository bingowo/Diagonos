#include <stdio.h>

int f(int n)
{
    int m,i;
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 4;
    if (n==4) return 7;
    if (n>4) return 2*f(n-1)-f(n-2)+f(n-3);
}

int main()
{
    int n;
    do{
        scanf("%d",&n);
        printf("%d",f(n));
    }
    while (n!=-1);
    return 0;
}