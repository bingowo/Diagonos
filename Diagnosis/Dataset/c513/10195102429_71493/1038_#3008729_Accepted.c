#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
ll data[205][205];


int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            scanf("%d",&data[i][j]);
    }

    ll ans = 0;



    //角在左上
    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= m; y++)
        {
            ll SUM = data[x][y];
            for(int r = 1; x + r <= n && y - r >= 1; r++)
            {
                for(int dx = 0, y1 = y - r; dx <= r; dx++)
                    SUM += data[x + dx][y1];
                if(SUM >= k)
                    ans++;
            }
        }

    //角在左下
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
        {
            ll SUM = data[x][y];
            for(int r = 1; x + r <= n && y + r <= m; r++)
            {
                for(int dx = 0, y1 = y + r; dx <= r; dx++)
                    SUM += data[x + dx][y1];
                if(SUM >= k)
                    ans++;
            }
        }


    //角在右下
    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= m; y++)
        {
            ll SUM = data[x][y];
            for(int r = 1; x - r >= 1 && y - r >= 1; r++)
            {
                for(int dx = 0, y1 = y - r; dx <= r; dx++)
                    SUM += data[x - dx][y1];
                if(SUM >= k)
                    ans++;
            }
        }
    //右上
    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= m; y++)
        {
            ll SUM = data[x][y];
            for(int r = 1; x - r >= 1 && y + r <= m; r++)
            {
                for(int dx = 0, y1 = y + r; dx <= r; dx++)
                    SUM += data[x - dx][y1];
                if(SUM >= k)
                    ans++;
            }
        }
    printf("%lld",ans);
}

