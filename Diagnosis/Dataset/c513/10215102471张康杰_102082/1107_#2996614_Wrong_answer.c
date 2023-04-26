#include <stdlib.h>
#include <stdio.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int light[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
        int i,j,cmd[3][3];
        for(i = 0;i < 3;i++)
        {
            for(j = 0;j < 3;j++)
            {
                scanf("%d",&cmd[i][j]);
                if(cmd[i][j] % 2 == 0)
                    continue;
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
        for(i = 0;i < 3;i ++)
        {
            for(j = 0;j < 3;j++)
            {
                printf("%d%c",light[i][j],(j == 2)?'\n':' ');
            }
        }
    }
    return 0;
}