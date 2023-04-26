#include <stdio.h>
#include <string.h>

int a[1000][1000];
int S[1000][1000];
int main()
{
    int t;
    scanf("%d",&t);
    int r,c,n,k,x,y;
    for(int z = 0; z < t; z++)
    {
        memset(a,0,sizeof(a));
        memset(S,0,sizeof(S));
        scanf("%d %d %d %d",&r,&c,&n,&k);
        for(int j = 0; j < n; j++)
        {
            scanf("%d %d",&x,&y);
             a[x][y] = 1;
        }
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + a[i][j];
            }
        }
        long long end = 0;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                for(int x = i; x <= r; x++)
                {
                     for(int y = j; y <= c; y++)
                     {
                         if(S[x][y] - S[i-1][y] - S[x][j-1] + S[i-1][j-1] >= k)
                            end++;
                     }
                }
            }
        }
        printf("case #%d:\n",z);
        printf("%d\n",end);
    }
    return 0;
}




