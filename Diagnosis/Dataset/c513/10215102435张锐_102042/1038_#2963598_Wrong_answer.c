#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M;long long int k;
    scanf("%d%d%lld",&N,&M,&k);
    int **a=(int**) malloc(N*sizeof(int*));
    for(int i=0;i<N;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*M);
        for(int j=0;j<M;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int ans=0;
    for (int x0 = 1; x0 < N; x0++)
    {
        for (int y0 = 1; y0 < M; y0++)
        { //枚举中心点
            for (int r = 1; x0 - r >= 0 && y0 - r >= 0; r++) //左上角为拓展方向
            { //枚举延申长度
                long long int s=0;
                int lb = y0 - r;
                int rb = y0+1; //计算当前行边界
                for(int x=x0-r;x<=x0;x++)
                {
                    rb--;
                    for(int y=rb;y>=lb;y--) s+=a[x][y];
                }
                if (s >= k) ans++;
            }
            for (int r = 1; x0 - r >= 0 && y0 - r >= 0; r++) //左下角为拓展方向
            { //枚举延申长度
                long long int s=0;
                int lb = y0 - r;
                int rb = y0+1; //计算当前行边界
                for(int x=x0;x>=x0-r;x--)
                {
                    rb--;
                    for(int y=lb;y<=rb;y++)
                        s+=a[x][y];
                }
                if (s >= k) ans++;
            }
            for (int r = 1; x0 - r >= 0 && y0 - r >= 0; r++) //右上角为拓展方向
            { //枚举延申长度
                long long int s=0;
                int lb = y0 - r;
                int rb = y0+1; //计算当前行边界
                for(int x=x0-r;x<=x0;x++)
                {
                    rb--;
                    for(int y=lb;y<=rb;y++)
                        s+=a[x][y];
                }
                if (s >= k) ans++;
            }
            for (int r = 1; x0 - r >= 0 && y0 - r >= 0; r++) //右下角为拓展方向
            { //枚举延申长度
                long long int s=0;
                int lb = y0 - r-1;
                int rb = y0; //计算当前行边界
                for(int x=x0;x>=x0-r;x--)
                {
                    lb++;
                    for(int y=lb;y<=rb;y++)
                        s+=a[x][y];
                }
                if (s >= k) ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
