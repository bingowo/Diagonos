#include<stdio.h>
long long f(int n)
{
    long long a[50];
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    a[4] = 8;
    for (int i = 5; i < n + 1; i++)
    {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4];
    }
    return a[n];
}
int main()
{
    int t;
    scanf("%d", &t);
    int n;
    for (int i = 0; i < t; i++)
    {
        scanf("%lld", &n);
        printf("case #%d:\n", i);
        printf("%lld\n", f(n));
    }
    return 0;
}