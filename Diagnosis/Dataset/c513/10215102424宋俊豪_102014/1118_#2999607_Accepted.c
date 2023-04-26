#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 201
int main()
{
    int a[N][N],w,h,degree,b[N][N];
    char p;
    scanf("%d %d %d %c",&w,&h,&degree,&p);
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
        {
            scanf("%d",&a[i][j]);
        }
    degree=(degree/90)%4;
    if(degree==0)
    {
        printf("%d %d\n",w,h);
         for(int i=1; i<=h; i++)
           {

           for(int j=1; j<=w; j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
           }
    }
    else if(degree==2)
    {
        printf("%d %d\n",w,h);
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
            {
                b[i][j]=a[h+1-i][w+1-j];
            }
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
    if((degree==1&&p=='R')||(degree==3&&p=='L'))
    {
        printf("%d %d\n",h,w);
        for(int i=1; i<=w; i++)
            for(int j=1; j<=h; j++)
            {
                 b[i][j]=a[h+1-j][i];
            }
         for(int i=1; i<=w; i++)
        {
            for(int j=1; j<=h; j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
    if((degree==1&&p=='L')||(degree==3&&p=='R'))
    {
        printf("%d %d\n",h,w);
        for(int i=1; i<=w; i++)
            for(int j=1; j<=h; j++)
            {
                 b[i][j]=a[j][w+1-i];
            }
         for(int i=1; i<=w; i++)
        {
            for(int j=1; j<=h; j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
