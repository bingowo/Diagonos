#include <stdio.h>

int main() {
    int matrix[201][201], sum[201][201] = {0};
    int m, n, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matrix[i][j]);
            sum[i][j] = sum[i][j - 1] + matrix[i][j];
        }
    }
    long long ans=0;
    //左上
    for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++){
            long long tmp=matrix[x][y];
            for(int r=1;x+r>=2 && x+r<=n && y-r>=1;r++){
                tmp+=(sum[x+r][y]-sum[x+r][y-r-1]);
                if(tmp>=k)
                    ans++;
            }
        }
    //左下
    for(int x=n;x>=1;x--)
        for(int y=1;y<=m;y++){
            long long tmp=matrix[x][y];
            for(int r=1;x-r<=n-1 && x-r>=1 && y-r>=1;r++){
                tmp+=(sum[x-r][y]-sum[x-r][y-r-1]);
                if(tmp>=k)
                    ans++;
            }
        }
    //右下
    for(int x=n;x>=1;x--)
        for(int y=1;y<=m;y++){
            long long tmp=matrix[x][y];
            for(int r=1;x-r>=1 && y+r<=m;r++){
                tmp+=(sum[x-r][y+r]);
                if(tmp>=k)
                    ans++;
            }
        }
    //右上
    for(int x = 1; x <= n; x++)
        for(int y = m; y >=1; y--)
        {
            long long tmp=matrix[x][y];
            for(int r = 1; x + r <= n && y - r-1 >=1; r++)
            {
                tmp += (matrix[x+r][y] - matrix[x+r][y -r-1]);
                if(tmp >= k)
                    ans++;
            }
        }
    printf("%lld\n",ans);
    return 0;
}
