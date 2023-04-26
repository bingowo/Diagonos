#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int point[6][6]={0};
        int res[6][6]={0};
        for(int i=1;i<4;i++)
            for(int j=1;j<4;j++)
                res[i][j]=1;
        for(int i=1;i<4;i++)
        {
            for(int j=1;j<4;j++)
                {
                    scanf("%d",&point[i][j]);
                    if(point[i][j]%2==1)
                    {
                        res[i-1][j]=1-res[i-1][j];
                        res[i][j-1]=1-res[i][j-1];
                        res[i][j]=1-res[i][j];
                        res[i][j+1]=1-res[i][j+1];
                        res[i+1][j]=1-res[i+1][j];
                    }
                }
        }
        for(int i=1;i<4;i++)
        {
            for(int j=1;j<4;j++)
            {
                printf("%d ",res[i][j]);
            }
            printf("%c",10);
        }


    }
    return 0;
}
