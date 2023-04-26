#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,cnt;
    scanf("%d",&T);
    for(cnt = 0;cnt < T;cnt++)
    {
        int r,c,n,k,i,j,p,q,x1,y1;
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
                        for(x1 = i;x1 <= p;x1++)
                            for(y1 = j;y1 <= q;y1++)
                            {
                                if(matrix[x1][y1] == 1)
                                    ans++;
                            }
                        if(ans >= k)
                            sum++;
                    }
        printf("case #%d:\n%d\n",cnt,sum);
    }

    return 0;
}
