#include <stdio.h>
#include <stdlib.h>


long long sum[207][207],A[207][207];
int main()
{
    int i,j,r,n,m,k;
    long long ans = 0;
    scanf("%d%d%d",&n,&m,&k);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)sum[i][j] = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)scanf("%lld",&A[i][j]);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)sum[i][j] = sum[i][j-1] + A[i][j];

    //向右下；
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            long long num = A[i][j];
            for(r = 1; j+r <= m && i+r <= n; r++)
                {
                    num += sum[i+r][j+r] - sum[i+r][j-1];
                   if(num>=k)ans++;
                }
        }

    //向左下；
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            long long num = A[i][j];
            for(r = 1; j-r >= 1 && i+r <= n; r++)
                {
                    num += sum[i+r][j] - sum[i+r][j-r-1];
                   if(num>=k)ans++;
                }
        }

    //向右上；
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            long long num = A[i][j];
            for(r = 1; j+r <= m && i-r >= 1; r++)
                {
                    num += sum[i-r][j+r] - sum[i-r][j-1];
                   if(num>=k)ans++;
                }
        }

    //向左上；
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            long long num = A[i][j];
            for(r = 1; j-r >= 1 && i-r >= 1; r++)
                {
                    num += sum[i-r][j] - sum[i-r][j-r-1];
                   if(num>=k)ans++;
                }
        }
        printf("%lld",ans);
    return 0;
}