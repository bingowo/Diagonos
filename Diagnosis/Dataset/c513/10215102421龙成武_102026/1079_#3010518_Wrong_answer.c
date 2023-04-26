#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int compar(const void* p, const void* q)
{
    return *(long long*)p - *(long long*)q<0? -1:1;
}
int main()
{
    int T, i, j, k, n, m, L, U, num;
    
    scanf("%d", &T);
    for (i = 0;i < T;i++)
    {
        int a[1002];
        long long dp[1002] = { 0 }, newp[1000000] = { -1 }, dpnewp[1000000] = { 0 };
        scanf("%d %d", &n, &m);
        num = 1;                      
        for (j = 1;j < n + 1;j++)
        {
            scanf("%d", &a[j]);
            dp[j] = dp[j - 1] + a[j];
        }
        for (j = 1;j < n + 1;j++)
        {
            for (k = 0;k < j;k++)
            {
                newp[num++] = dp[j] - dp[k];            //num为newp里元素个数
            }
        }
        qsort(newp, num, sizeof(long long), compar);
        for (j = 1;j < num;j++)
        {
            dpnewp[j] = dpnewp[j - 1] + newp[j];
        }
        printf("case #%d:\n", i);
        while (m--)
        {
            scanf("%d%d", &L, &U);
            printf("%lld\n", dpnewp[U] - dpnewp[L]);
        }
    }
    return 0;
}
