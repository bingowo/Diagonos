#include <stdio.h>
#define MAXN 40

void clear(int a[]);

void add(int a[], int b[], int c[]);

int main()
{
    int T;
    scanf("%d", &T);
    for(int k=0; k<T; k++)
    {
        int dp[125][MAXN];
        int n;
        scanf("%d", &n);

        dp[0][0] = 0;
        dp[1][0] = dp[2][0] = 1;

        for(int i=2; i<=n; i++)
        {
            add(dp[i-1], dp[i-2], dp[i]);
        }

        int i=MAXN-1;

        for(i=MAXN-1; i>=1;)
        {
            if(dp[n][i] == 0) i--;
            else break;
        }
        
        printf("case #%d:\n", k);

        for(; i>=0; i--)
        {
            printf("%d", dp[n][i]);//从高位输出
        }

        printf("%c", '\n');
    }

    return 0;
}

void clear(int a[])
{
    for(int i=0; i<MAXN; i++) a[i] = 0;
}

void add(int a[], int b[], int c[])
{
    clear (c);

    for(int i=0; i<MAXN; i++)
    {
        c[i] += a[i] + b[i];
        if(c[i] >= 10)
        {
            c[i] -= 10;
            c[i+1] += 1;
        }
    }
}