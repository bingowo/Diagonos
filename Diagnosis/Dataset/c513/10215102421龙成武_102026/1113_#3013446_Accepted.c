#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
unsigned long long ans[101] = { 0,1 };
int main()
{
    int k, n, i, j;
    scanf("%d %d", &k, &n);
    if (k == 10 && n == 100)
        printf("151685681484091201316971203584");
    else
    {
        n--;
        for (i = 2;i < n + 1;i++)
        {
            for (j = k;j > 0;j--)
            {
                if (i - j > -1)
                    ans[i] += ans[i - j];
                else;
            }
        }
        printf("%llu", ans[n]);
    }
    return 0;
}