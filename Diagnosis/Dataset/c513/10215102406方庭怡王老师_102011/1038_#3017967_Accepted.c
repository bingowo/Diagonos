#include<stdio.h>

typedef long long ll;

ll data[205][205];
ll S[205][205];

int main()
{
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            scanf("%d", &data[i][j]);
    }
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
            S[i][j] = S[i - 1][j] + data[i][j];
    }

    ll ans = 0;

    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= m; y++)
        {
            ll SUM = data[x][y];
            for(int r = 1; x + r <= n && y - r >= 1; r++)
            {
                SUM += (S[x + r][y - r] - S[x - 1][y - r]);
                if(SUM >= k)
                    ans++;
            }
            SUM = data[x][y];
            for(int r = 1; x + r <= n && y + r <= m; r++)
            {
                SUM += (S[x + r][y + r] - S[x - 1][y + r]);
                if(SUM >= k)
                    ans++;
            }
            SUM = data[x][y];
            for(int r = 1; x - r >= 1 && y - r >= 1; r++)
            {
                SUM += (S[x][y - r] - S[x - r -1][y - r]);
                if(SUM >= k)
                    ans++;
            }
            /////////////////////////////////////////
            SUM = data[x][y];
            for(int r = 1; x - r >= 1 && y + r <= m; r++)
            {
                SUM += (S[x][y + r] - S[x - r - 1][y + r]);
                if(SUM >= k)
                    ans++;
            }
        }

    printf("%lld\n", ans);
}