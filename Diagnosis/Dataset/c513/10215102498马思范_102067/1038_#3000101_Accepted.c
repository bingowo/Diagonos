#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    long long data[205][205];
    long long s[205][205];
    int n,m,k;
    scanf("%d%d%d", &n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%d", &data[i][j]);
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
            s[i][j]=s[i-1][j]+data[i][j];
    }

    long long ans = 0;
    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= m; y++)
        {
            long long sum = data[x][y];
            for(int r = 1; x + r <= n && y - r >= 1; r++)
            {
                sum += (s[x + r][y - r] - s[x - 1][y - r]);
                if(sum >= k)
                    ans++;
            }

            sum = data[x][y];
            for(int r = 1; x + r <= n && y + r <= m; r++)
            {
                sum += (s[x + r][y + r] - s[x - 1][y + r]);
                if(sum >= k)
                    ans++;
            }

            sum = data[x][y];
            for(int r = 1; x - r >= 1 && y - r >= 1; r++)
            {
                sum += (s[x][y - r] - s[x - r - 1][y - r]);
                if(sum >= k)
                    ans++;
            }

            sum = data[x][y];
            for(int r = 1; x - r >= 1 && y + r <= m; r++)
            {
                sum += (s[x][y + r] - s[x - r - 1][y + r]);
                if(sum >= k)
                    ans++;
            }
    }
    printf("%lld\n", ans);
}
