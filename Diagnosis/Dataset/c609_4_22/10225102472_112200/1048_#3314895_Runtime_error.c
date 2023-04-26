#include <stdio.h>
#include <string.h>

#define MAXN 40

void clear(int a[]);
void add(int a[], int b[], int c[]);

int main()
{
    int T;
    scanf("%d", &T);
    for(int k = 0; k < T; k++)
    {
        int dp[120][MAXN] = {0};
        int n;
        scanf("%d", &n);
        dp[0][0] = 0;
        dp[1][0] = dp[2][0] = 1;
        for(int i = 3; i <= n; i++)
        {
            add(dp[i-1], dp[i-2], dp[i]);
        }
        printf("case #%d:\n", k);
        int i = MAXN - 1;
        while (i > 0 && dp[n][i] == 0) i--;
        for (; i >= 0; i--) printf("%d", dp[n][i]);
        printf("\n");
    }

    return 0;
}

void clear(int a[])
{
    memset(a, 0, sizeof(int) * MAXN);
}

void add(int a[], int b[], int c[])
{
    clear(c);
    for (int i = 0; i < MAXN - 1; i++)
    {
        c[i] += a[i] + b[i];
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
}
