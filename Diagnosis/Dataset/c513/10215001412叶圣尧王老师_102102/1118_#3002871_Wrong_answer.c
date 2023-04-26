#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int w,h,D;char c;scanf("%d %d %d %c",&w,&h,&D,&c);
    int j,i;
    int a[h+1][w+1];
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
            scanf("%d",&a[i][j]);
    }
    D%=360;
    if(c=='L')D=(360-D)%360;
    if(D==0||D==180)
    {
        if(D==0)
        {
            printf("%d %d\n",w,h);
            for(i=1;i<=h;i++)
            {
                for(j=1;j<=w;j++)
                {
                    if(j!=1)putchar(' ');
                    printf("%d",a[i][j]);
                }
                putchar('\n');
            }
        }
        else
        {
            printf("%d %d\n",w,h);
            for(i=h;i>=1;i--)
            {
                for(j=w;j>=1;j--)
                {
                    if(i!=w)putchar(' ');
                    printf("%d",a[i][j]);
                }
                putchar('\n');
            }
        }
    }
    else 
    {
        int b[w+1][h+1];
        if(D==90)
        {
            for(i=1;i<=h;i++)
            {
                for(j=1;j<=w;j++)
                    b[j][h-i+1]=a[i][j];
            }
            printf("%d %d\n",h,w);
            for(i=1;i<=h;i++)
            {
                for(j=1;j<=w;j++)
                {
                    if(j!=1)putchar(' ');
                    printf("%d",b[i][j]);
                }
                putchar('\n');
            }
        }
        if(D==270)
        {
            for(i=1;i<=h;i++)
            {
                for(j=1;j<=w;j++)
                    b[w-j+1][i]=a[i][j];
            }
            printf("%d %d\n",h,w);
            for(i=1;i<=h;i++)
            {
                for(j=1;j<=w;j++)
                {
                    if(j!=1)putchar(' ');
                    printf("%d",b[i][j]);
                }
                putchar('\n');
            }
        }
    }
}