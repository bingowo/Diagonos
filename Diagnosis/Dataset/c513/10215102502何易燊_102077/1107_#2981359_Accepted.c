#include <stdio.h>

int light[5][5];

void init()
{
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++) light[i][j] = 1;
}

void trans(int x,int y,int num)
{
    if (num&1)
    {
        light[x][y]^=1;
        light[x-1][y]^=1;
        light[x+1][y]^=1;
        light[x][y-1]^=1;
        light[x][y+1]^=1;
    }
}

int main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        init();
        int num;
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
            {
                scanf("%d",&num);
                trans(i,j,num);
            }
        printf("case #%d:\n",i);
        for (int i=1;i<=3;i++)
        {
            for (int j=1;j<=3;j++)
                printf("%d ",light[i][j]);
            printf("\n");
        }
    }
    return 0;
}