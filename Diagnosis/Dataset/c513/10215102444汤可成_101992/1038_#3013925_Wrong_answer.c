#include <stdio.h>
#include <stdlib.h>

long long data[205][205];
long long suml[205][205];

int main()
{
    //输入
    int n = 0, m = 0, k = 0;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i<n; i++)
    {
        for(int j = 1; j<m; j++)
        {
            scanf("%lld", &data[i][j]);
        }
    }

    //部分和，简化后续计算
    for(int j = 1; j<m; j++)
    {
        for(int i = 1; i<n; i++)
        {
            suml[i][j] = suml[i-1][j] + data[i][j];
        }
    }

    long long ans = 0;

    //数
    for(int x = 1; x<=n; x++)
    {
        for(int y = 1; y<m; y++)
        {
            long long sum = data[x][y];

            //分四种形状
            for(int d = 1; x+d<=n && y+d<=m; d++)
            {
                sum += suml[x+d][y+d] - suml[x-1][y+d];
                if(sum >= k)
                    ans++;
            }

            sum = data[x][y];
            for(int d = 1; x-d>=1 && y+d<=m; d++)
            {
                sum += suml[x][y+d] - suml[x-d-1][y+d];
                if(sum >= k)
                    ans++;
            }

            sum = data[x][y];
            for(int d = 1; x-d>=1 && y-d>=1; d++)
            {
                sum += suml[x][y-d] - suml[x-d-1][y-d];
                if(sum >= k)
                    ans++;
            }

            sum = data[x][y];
            for(int d = 1; x+d<=n && y-d>=1; d++)
            {
                sum += suml[x+d][y-d] - suml[x-1][y-d];
                if(sum >= k)
                    ans++;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
