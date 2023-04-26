#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll data[205][205];
ll S[205][205];

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    // 这个地方因为要与S对应，所以从1开始输入
    for(int i = 1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            scanf("%d",&data[i][j]);
        }
    }
    // 获得列累加和，空出0是因为之后相减的需要，
    // 如直角在第二行的三角形加累加和时要减去第一行的累加和，
    // 而直角在最上的三角形，如果用相同算法，顶0时会减去下标是-1的元素，
    // 为避免下标越界，从1开始输入，
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++)
            S[i][j] = S[i-1][j] + data[i][j];
    }

    ll ans = 0;

    // 遍历：以每个值为直角顶点时
    for(int x = 1;x <= n; x++){
        for(int y=1;y<=m;y++){
            ll SUM = data[x][y];
            // 朝右下
            for(int r = 1;x+r<=n && y-r >= 1;r++){
                SUM += (S[x+r][y-r] - S[x-1][y-r]);
                if(SUM >= k)
                    ans++;
            }

            SUM = data[x][y];
            // 朝左下
            for(int r = 1;x+r<=n && y+r <= m;r++){
                SUM += (S[x+r][y+r] - S[x-1][y+r]);
                if(SUM >= k)
                    ans++;
            }

            SUM = data[x][y];
            // 朝右下
            for(int r = 1;x-r>=1 && y-r>=1;r++){
                SUM += (S[x][y-r] - S[x-r-1][y-r]);
                if(SUM >= k)
                    ans++;
            }

            SUM = data[x][y];
            // 朝右下
            for(int r = 1;x-r>=1 && y+r<=m;r++){
                SUM += (S[x][y+r] - S[x-r-1][y+r]);
                if(SUM >= k)
                    ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
