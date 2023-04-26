#include <stdlib.h>
#include <stdio.h>

void reverse(int*a)
{
    if(*a == 0)
        *a = 1;
    else
        *a = 0;
}

int main()
{
    int T,k;
    scanf("%d",&T);
    for(k = 0;k < T;k++)
    {
        int light[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
        int i,j,cmd[3][3];
        for(i = 0;i < 3;i++)
        {
            for(j = 0;j < 3;j++)
            {
                scanf("%d",&cmd[i][j]);
                if(cmd[i][j] % 2 == 0);
                else
                {
                    reverse(&light[i][j]);
                    reverse(&light[i - 1][j]);
                    reverse(&light[i + 1][j]);
                    reverse(&light[i][j - 1]);
                    reverse(&light[i][j + 1]);
                }
            }
        }
        printf("case #%d:\n",k);
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