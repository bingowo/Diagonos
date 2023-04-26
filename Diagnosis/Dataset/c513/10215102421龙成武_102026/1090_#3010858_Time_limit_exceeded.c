#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int n;
    double ans;
    while(scanf("%d",&n))
    {
        if (n == 0) break;
        ans = pow(10, n * log10(n));
        while (ans > 10)
        {
            ans = ans / 10;
        }
        printf("%d\n", (int)ans);
    }

    return 0;
}

