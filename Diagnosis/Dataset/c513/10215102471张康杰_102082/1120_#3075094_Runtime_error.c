#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int r,c,n,k,i,j,p,q,x,y;
        int sum = 0;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int matrix[r][c];
        memset(matrix,0,sizeof(int) * r * c);
        for(i = 0;i < n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            matrix[x][y] = 1;
        }
        for(i = 0;i < r;i++)
            for(j = 0;j < c;j++)
                for(p = i;p < r;p++)
                    for(q = j;q < c;q++)
                    {
                        int ans = 0;
                        for(x = i;x <= p;x++)
                            for(y = j;y <= q;y++)
                            {
                                if(matrix[x][y] == 1)
                                    ans++;
                            }
                        if(ans >= k)
                            sum++;
                    }
        }
    return 0;
}
