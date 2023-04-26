#include <stdlib.h>
#include <stdio.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int light[5][5] = {{0,0,0,0,0},{0,1,1,1,0},{0,1,1,1,0},{0,1,1,1,0},{0,0,0,0,0}};
        int i,j,cmd[5][5];
        for(i = 1;i < 4;i++)
        {
            for(j = 1;j < 4;j++)
            {
                scanf("%d",&cmd[i][j]);
                if(cmd[i][j] % 2 == 0);
                else
                {
                    ~light[i][j];
                    ~light[i - 1][j];
                    ~light[i + 1][j];
                    ~light[i][j - 1];
                    ~light[i][j + 1];
                }
            }
        }
        printf("case #%d:\n",i);
        for(i = 1;i < 4;i ++)
        {
            for(j = 1;j < 4;j++)
            {
                printf("%d%c",light[i][j],(j == 3)?'\n':' ');
            }
        }
    }
    return 0;
}