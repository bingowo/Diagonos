#include<stdio.h>
int main()
{
    int t;
    long long int n;
    int a[100];
    scanf("%d", &t);
    for(int i = 0;  i < t; i++)
    {
        int j = 0;
        scanf("%lld", &n);
        for (j = 0; n / 2333; j++, n = n / 2333)
        {
            a[j] = n % 2333;
        }
        a[j] = n % 2333;
        for (; j > 0; j--)
        {
            printf("%d ", a[j]);
        }
        printf("%d", a[j]);
    }
}
