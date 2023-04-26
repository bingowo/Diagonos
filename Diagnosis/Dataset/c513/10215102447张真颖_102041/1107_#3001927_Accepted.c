#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int light[3][3]={0};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int m=0;
                scanf("%d",&m);
                if(m%2)
                {
                    light[i][j]=(light[i][j]==0?1:0);
                    if(i>0) light[i-1][j]=(light[i-1][j]==0?1:0);
                    if(i<2) light[i+1][j]=(light[i+1][j]==0?1:0);
                    if(j>0) light[i][j-1]=(light[i][j-1]==0?1:0);
                    if(j<2) light[i][j+1]=(light[i][j+1]==0?1:0);
                }
            }
        }
        printf("case #%d:\n",cas);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                printf("%d%c",light[i][j]==0?1:0,j+1<3?' ':'\n');
        }
    }
    return 0;
}