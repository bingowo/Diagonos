#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 110

typedef struct
{
    int cnt, v[N];
} BIGINT;

BIGINT int2BIG(int x) // int转换成BIGINT
{
    BIGINT R = {0, {0}};
    do
    {
        R.v[R.cnt++] = x % 10;
        x /= 10;
    } while (x > 0);
    return R;
}

BIGINT mul(BIGINT S, BIGINT T) // 两个大整数相乘
{
    BIGINT R = {S.cnt + T.cnt, {0}};
    int carry = 0;
    for (int i = 0; i < T.cnt; i++)
    {
        int t, k, j;
        for (j = 0; j < S.cnt; j++)
        {
            t = S.v[j] * T.v[i] + carry + R.v[i + j];
            R.v[i + j] = t % 10;
            carry = t / 10;
        }
        k = i + j;
        while (carry > 0)
        {
            t = carry + R.v[k];
            R.v[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }
    if (!R.v[S.cnt + T.cnt - 1])
        R.cnt--;
    return R;
}

BIGINT Pow(BIGINT a, int n) // 计算a的n次方
{
    BIGINT r;
    if (n == 0)
        return int2BIG(1);
    if (n == 1)
        return a;
    r = Pow(a, n / 2);
    r = mul(r, r);
    if (n % 2)
        r = mul(r, a);
    return r;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++)
    {
        int a, n;
        scanf("%d%d", &a, &n);
        printf("case #%d:\n", z);
        BIGINT A = int2BIG(a);
        BIGINT res = Pow(A, n);
        for (int i = res.cnt - 1; i >= 0; i--)
        {
            printf("%d", res.v[i]);
        }
        printf("\n");
    }
    return 0;
}