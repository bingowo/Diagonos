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
    for (int x0 = 0; x0 < N; x0++)//左上角
    {
        for (int y0 = 0; y0 < M; y0++)
        { //枚举中心点
            for (int r = 1; x0 + r<N && y0 + r <M; r++) //左上角为拓展方向
            { //枚举延申长度
                long long int s=0;
                int lb = y0;
                int rb = y0+r+1; //计算当前行边界
                for(int x=x0;x<=x0+r;x++)
                {
                    rb--;
                    for(int y=rb;y>=lb;y--) s+=a[x][y];
                }
                if (s >= k)
                {
                    for(; x0 + r<N && y0 + r <M; r++) ans++;
                }
            }
        }
    }
    for (int x0 = 0; x0 < N; x0++)//you上角
    {
        for (int y0 = M-1; y0 >=0; y0--)
        { //枚举中心点
            for (int r = 1; y0 -r>=0 && x0 + r <N; r++)
            { //枚举延申长度
                long long int s=0;
                int lb = y0-r-1;
                int rb = y0; //计算当前行边界
                for(int x=x0;x<=x0+r;x++)
                {
                    lb++;
                    for(int y=rb;y>=lb;y--) s+=a[x][y];
                }
                if (s >= k)
                {
                    for(; y0 -r>=0 && x0 + r <N; r++) ans++;
                }
            }
        }
    }
    for (int x0 = N-1; x0 >=0; x0--)//左下角
    {
        for (int y0 = 0; y0 < M; y0++)
        { //枚举中心点
            for (int r = 1; x0 - r>=0 && y0 + r <M; r++)
            { //枚举延申长度
                long long int s=0;
                int lb = y0;
                int rb = y0+r+1; //计算当前行边界
                for(int x=x0;x>=x0-r;x--)
                {
                    rb--;
                    for(int y=rb;y>=lb;y--) s+=a[x][y];
                }
                if (s >= k)
                {
                    for(; x0 - r>=0 && y0 + r <M; r++) ans++;
                }
            }
        }
    }
    for (int x0 = N-1; x0 >=0; x0--)//右下角
    {
        for (int y0 = M-1; y0 >=0; y0--)
        { //枚举中心点
            for (int r = 1; x0 - r>=0 && y0 - r >=0; r++) //左上角为拓展方向
            { //枚举延申长度
                long long int s=0;
                int lb = y0-r-1;
                int rb = y0; //计算当前行边界
                for(int x=x0;x>=x0-r;x--)
                {
                    lb++;
                    for(int y=lb;y<=rb;y++) s+=a[x][y];
                }
                if (s >= k)
                {
                    for(; x0 - r>=0 && y0 - r >=0; r++) ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
