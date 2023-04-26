#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m,k;
int grid[200][200];
int cnt;
int dir[4][2] = {-1,-1,-1,1,1,-1,1,1};

void deal(int x,int y)
{
    for (int i=0;i<4;i++)
    {
        int ux = x, uy = y;
        int sum = 0;
        int layer = 0;
        while (ux>=0&&ux<n&&uy>=0&&uy<m)
        {
            for (int j=0;j<=layer;j++) sum += grid[ux-j*dir[i][0]][y+j*dir[i][1]];
            if (sum>=k) cnt++;
            ux += dir[i][0], uy += dir[i][1];
            layer++;
        }
    }
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) scanf("%d",&grid[i][j]);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) deal(i,j);
    printf("%d\n",cnt);
    return 0;
}