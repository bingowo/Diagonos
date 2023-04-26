#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int a[200][200];
    int n,m,k;
    long long int ans=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for (int x0 = 1; x0 <= n; x0++) {
        for (int y0 = 1; y0 <= m; y0++) {		//枚举中心点
            long long s = a[x0][y0];
            for (int r = 1; x0 - r > 0 && y0 - r > 0; r++)
            {	//枚举延申长度
                int lb = y0 - r;
                int rb = y0;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s += a[x0 - r][y];
                if (s >= k) ans++;
            }
             s = a[x0][y0];
            for (int r = 1; x0 - r > 0 && y0 + r <= m; r++)
            {	//枚举延申长度
                int lb = y0;
                int rb = y0+r;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s += a[x0 - r][y];
                if (s >= k) ans++;
            }
             s = a[x0][y0];
            for (int r = 1; x0 + r <= n && y0 - r > 0; r++)
            {	//枚举延申长度
                int lb = y0 - r;
                int rb = y0;			//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s += a[x0 + r][y];
                if (s >= k) ans++;
            }
             s = a[x0][y0];
            for (int r = 1; x0 + r <= n && y0 + r <= m; r++)
            {	//枚举延申长度
                int lb = y0;
                int rb = y0+r;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s += a[x0 + r][y];
                if (s >= k) ans++;
            }
        }}


    printf("%lld",ans);


}
