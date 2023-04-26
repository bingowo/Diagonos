#include <stdio.h>
#include <stdlib.h>
#define N 100

 void method(int e,int f)
{
    char x[N];
    char d[37] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int c = 0;
    int g = e;
    if(e < 0)
    {
        e = -e;
    }
    do
    {
        x[c] = d[e % f];
        c++;
        e = e/f;

    }while(e > 0);
    if(g < 0)
    {
        x[c++] = '-';
        x[c] = 0;
    }
    else
    {
        x[c] = 0;
    }

    for(int i = 0,j = c - 1;i < j; i++,j--)
    {
        char e;
        e = x[i];
        x[i] = x[j];
        x[j] = e;
    }

    printf("%s\n",x);
}

int main()
{
    int n;
    int a[N];
    int b[N];
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }
    for(int i = 0; i < n; i++)
    {
        method(a[i],b[i]);
    }

    return 0;
}