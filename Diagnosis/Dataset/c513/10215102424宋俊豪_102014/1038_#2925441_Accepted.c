#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
long long F[205][205]= {0},a[205][205]={0};

int main()
{
    int n,m,k,ans=0;
    scanf("%d %d %d",&n,&m,&k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d",&a[i][j]);
            F[i][j] = F[i][j - 1] + a[i][j];
        }
    for (int x0 = 1; x0 <= n; x0++)
    {
        for (int y0 = 1; y0 <= m; y0++)
        {
            long long s = a[x0][y0];
            for (int r = 1; x0 - r > 0 && y0 - r > 0; r++)
            {
                int lb = y0 - r;
                int rb = y0;				//计算当前行边界
                s += F[x0 - r][rb] - F[x0 - r][lb - 1];	//累计当前行的和
                if (s >= k) ans++;
            }
        }
    }
    for (int x0 = 1; x0 <= n; x0++)//右上
    {
        for (int y0 = 1; y0 <= m; y0++)
        {
            long long s = a[x0][y0];
            for (int r = 1; x0 - r > 0 && y0 +r <m+1; r++)
            {
                int lb = y0 + r;
                int rb = y0;				//计算当前行边界
                s += F[x0 - r][lb] - F[x0 - r][rb-1];	//累计当前行的和
                if (s >= k) ans++;
            }
        }
    }
    for (int x0 = 1; x0 <= n; x0++)//右下
    {
        for (int y0 = 1; y0 <= m; y0++)
        {
            long long s = a[x0][y0];
            for (int r = 1; x0+ r < n+1 && y0 +r <m+1; r++)
            {
                int lb = y0 + r;
                int rb = y0;				//计算当前行边界
                s += F[x0 +r][lb] -F[x0 + r][rb-1];	//累计当前行的和
                if (s >= k) ans++;
            }
        }
    }
    for (int x0 = 1; x0 <= n; x0++)//左下
    {
        for (int y0 = 1; y0 <= m; y0++)
        {
            long long s = a[x0][y0];
            for (int r = 1; x0+ r < n+1 && y0 -r>0; r++)
            {
                int lb = y0 - r;
                int rb = y0;				//计算当前行边界
                s += F[x0 +r][rb] - F[x0 + r][lb-1];	//累计当前行的和
                if (s >= k) ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
