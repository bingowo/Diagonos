#include <stdio.h>
#include <stdlib.h>
#define N 100

 char* method(int e,int f)
{
    char x[N];
    char d[37] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int c = 0;
    if(e < 0)
    {
        x[c++] = '-';
        e = -e;
    }
    do
    {
        x[c] = d[e % f];
        c++;
        e = e/10;

    }while(e > 0);
    x[c] = '0';

    for(int i = 0,j = c;i < j; i++,j--)
    {
        char e;
        e = x[i];
        x[i] = x[j];
        x[j] = e;
    }
    return x;
}

int main()
{
    int n;
    int a[N];
    int b[N];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d %s\n",a[i],method(a[i],b[i]));
    }

    return 0;
}