#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int n;
    double ans, f;
    while (scanf("%d", &n))
    {
        if (n == 0) break;
        //ans = pow(10, n * log10(n));  实际上起作用的只是小数部分，所以可以减少计算次数
        f = n * log10(n) - (int)n * log10(n);
        ans = pow(10, f);
        while (ans > 10)
        {
            ans = ans / 10;
        }
        printf("%d\n", (int)ans);
    }

    return 0;
}

