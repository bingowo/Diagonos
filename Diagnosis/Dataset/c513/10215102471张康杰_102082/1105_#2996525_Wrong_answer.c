    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        int W,H,i,j,k,m;
        scanf("%d %d",&W,&H);
        int ar[H][W];
        int ar1[8],cnt = 0,mini = 256,mini_cur = 0;
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
                ar1[cnt++] = (ar[i - 1][j - 1] >= ar[i][j])?1:0;
                ar1[cnt++] = (ar[i - 1][j] >= ar[i][j])?1:0;
                ar1[cnt++] = (ar[i - 1][j + 1] >= ar[i][j])?1:0;
                ar1[cnt++] = (ar[i][j + 1] >= ar[i][j])?1:0;
                ar1[cnt++] = (ar[i + 1][j + 1] >= ar[i][j])?1:0;
                ar1[cnt++] = (ar[i + 1][j] >= ar[i][j])?1:0;
                ar1[cnt++] = (ar[i + 1][j - 1] >= ar[i][j])?1:0;
                ar1[cnt++] = (ar[i][j - 1] >= ar[i][j])?1:0;
                cnt = 0;
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
                printf("%d%c",mini,(j == W - 2)?'\n':' ');
            }
        }
        return 0;
    }