#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int s[200][200];
    int z,j;
    for(z=1;z<=n;z++)
    {
        for(j=1;j<=m;j++) scanf("%d",&s[z][j]);
    }
    int ans=0;
    for (int x0 = 1; x0 <= n; x0++) {
        for (int y0 = 1; y0 <= m; y0++) {

            long long a = s[y0][x0];
            long long sum=a;

            for (int r = 1; x0 - r > 0 && y0 - r > 0; r++) {
                int lb = y0 - r;
                int rb = y0;
                for (int y = lb; y <= rb; y++)
                    sum += s[x0 - r][y];
                if (sum >= k) ans++;
            }

            sum=a;

            for (int r = 1; x0 + r <=m && y0 - r > 0; r++) {
                int lb = y0 - r;
                int rb = y0;

                for (int y = lb; y <= rb; y++)
                    sum += s[x0+r][y];
                if (sum >= k) ans++;
            }

            sum=a;

            for (int r = 1; x0 + r <= m && y0 - r <= n; r++) {
                int rb = y0 + r;
                int lb = y0;
                for (int y = lb; y <= rb; y++)
                    sum += s[x0 + r][y];
                if (sum >= k) ans++;
            }

            sum=a;

            for (int r = 1; x0 - r > 0 && y0 + r <= n; r++) {
                int lb = y0;
                int rb = y0+r;
                for (int y = lb; y <= rb; y++)
                    sum += s[x0 - r][y];
                if (sum >= k) ans++;
            }
        }
    }
            printf("%d",ans+1);
    return 0;
}
