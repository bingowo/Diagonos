#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int d[5][5];int a[5][5],i,j;
        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]=a[i][j]%2;
                d[i][j]=1;
            }
        }
        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {
                if(a[i][j]==1)
                {
                    d[i-1][j]=1-d[i-1][j];
                    d[i][j-1]=1-d[i][j-1];
                    d[i][j+1]=1-d[i][j+1];
                    d[i+1][j]=1-d[i+1][j];
                    d[i][j]=1-d[i][j];
                }
            }
        }
        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {
                printf("%d",d[i][j]);
                if(j!=3)putchar(' ');
            }
            putchar('\n');
        }
    }
}