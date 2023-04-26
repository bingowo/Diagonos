#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,d,i,j;
    int a[200][200],b[200][200];
    char c[2];
    scanf("%d%d",&x,&y);
    scanf("%d",&d);
    d=d%360;
    scanf("%s",c);
    if(c[0]=='L') d=360-d;
    for(i=0;i<y;i++)
        for(j=0;j<x;j++)
        {
            scanf("%d",&a[i][j]);
        }
    if(d==0)
    {

        printf("%d %d\n",x,y);
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    if(d==90)
    {
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                b[j][y-i-1]=a[i][j];
            }
        }
        printf("%d %d\n",y,x);
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
    if(d==180)
    {
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                b[y-i-1][x-j-1]=a[i][j];
            }
        }
        printf("%d %d\n",x,y);
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
    if(d==270)
    {
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                b[x-j-1][i]=a[i][j];
            }
        }
        printf("%d %d\n",y,x);
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
}
