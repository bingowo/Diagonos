#include<stdio.h>

long long f(long long n)
{
    long long a[100];
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for(int i = 4; i < 100; i++)
    {
        a[i] =  a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4];
    }
    return a[n];
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        long long n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",f(n));
    }
    return 0;
}

