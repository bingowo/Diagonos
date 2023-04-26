#include<stdio.h>

int main()
{
    long long a[21];
    long long b[21];
    a[0] = 0;
    a[1] = 1;
    b[0] = 0;
    b[1] = 1;
    for(int i = 2; i < 21; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i] - b[i-2];
    }
    int n;
    while((scanf("%d",&n))&& n != -1)
    {
        printf("%lld\n",a[n]+b[n]);
    }
    return 0;
}
