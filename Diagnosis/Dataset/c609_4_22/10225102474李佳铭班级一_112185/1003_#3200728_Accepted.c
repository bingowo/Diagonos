#include <stdio.h>
#include <stdlib.h>
#define N 10000

void method(long long b)
{
    long long a[N];
    int i = 0;
    do
    {
        a[i++] = b % 2333;
    }while(b /= 2333);
    for(int j = 0,k = i - 1;j < k; j++,k--)
    {
        long long c = a[j];
        a[j] = a[k];
        a[k] = c;
    }
    for(int j = 0;j < i;j++)
    {
        printf("%lld ",a[j]);
    }
}

int main()
{
    int n;
    long long a[N];
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i = 0; i < n; i++)
    {

        method(a[i]);
        printf("\n");
    }

    return 0;
}