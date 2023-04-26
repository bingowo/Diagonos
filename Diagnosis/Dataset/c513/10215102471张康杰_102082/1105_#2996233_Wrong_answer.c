#include <stdio.h>
#include <stdlib.h>

int main()
{
    int W,H,i,j,k,m;
    scanf("%d %d",&W,&H);
    int ar[H][W];
    int ar1[8],cnt = 0,mini = 0,mini_cur = 256;
    for(i = 0;i < H;i++)
    {
        for(j = 0;j < W;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    for(i = 1;i < H - 1;i++)
    {
        for(j = 1;j < W - 1;j++)
        {
            for(k = -1;k <= 1;k++)
            {
                for(m = -1;m <= 1;m++)
                {
                    if(k == 0 && m == 0)
                        continue;
                    if(ar[i + k][j + m] >= ar[i][j])
                    {
                        ar1[cnt++] = 1;
                    }
                    else
                        ar1[cnt++] = 0;
                }
            }
            for(int pos = 0;pos < 8;pos++)
            {
                for(k = pos;k < 8;k++)
                {
                    mini_cur = mini_cur * 2 + ar1[k];
                }
                for(m = 0;m < pos;m++)
                {
                    mini_cur = mini_cur * 2 +ar1[m];
                }
                if(mini_cur < mini)
                    mini = mini_cur;
                mini_cur = 0;
            }
            printf("%d%c",mini,(j == W - 1)?'\n':' ');
        }
    }
    return 0;
}