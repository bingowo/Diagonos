#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[200][200];
int main()
{
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&w,&h,&d,&c);
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    d/=90;
    d%=4;
    switch(d)
    {
    case 0:
        printf("%d %d\n",w,h);
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w-1;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("%d\n",a[i][w-1]);
        }
        break;
    case 1:
        printf("%d %d\n",h,w);
        if(c=='R')
        {
            for(int i=0;i<w;i++)
            {
                for(int j=h-1;j>0;j--)
                {
                    printf("%d ",a[j][i]);
                }
                printf("%d\n",a[0][i]);
            }
        }
        else if(c=='L')
        {
            for(int i=w-1;i>=0;i--)
            {
                for(int j=0;j<h-1;j++)
                {
                    printf("%d ",a[j][i]);
                }
                printf("%d\n",a[h-1][i]);
            }
        }
        break;
    case 2:
        printf("%d %d\n",w,h);
        for(int i=h-1;i>=0;i--)
        {
            for(int j=w-1;j>0;j--)
            {
                printf("%d ",a[i][j]);
            }
            printf("%d\n",a[i][0]);
        }
        break;
    case 3:
        printf("%d %d\n",h,w);
        if(c=='R')
        {
           for(int i=w-1;i>=0;i--)
            {
                for(int j=0;j<h-1;j++)
                {
                    printf("%d ",a[j][i]);
                }
                printf("%d\n",a[h-1][i]);
            }
        }
        else if(c=='L')
        {
             for(int i=0;i<w;i++)
            {
                for(int j=h-1;j>0;j--)
                {
                    printf("%d ",a[j][i]);
                }
                printf("%d\n",a[0][i]);
            }
        }
        break;
    }
    return 0;
}
