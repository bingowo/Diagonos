#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        int L[15] = {0};
        int i = 0;
        do
        {
            int a = 0;
            a = n % 2333;
            L[i++] = a;
            n = n / 2333;
        } while (n>0);
        for (int e = i-1;e>=0;--e)
        {
            printf("%d ", L[e]);
        }
        printf("\n");
    }
    return 0;
}