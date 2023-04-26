#include<stdio.h>
int main()
{
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&w,&h,&d,&c);
    int a[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int r=d/90;
    if(r%4==0)
    {
        printf("%d %d\n",w,h);
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    else if((r%4==1&&c=='R')||(r%4==3&&c=='L'))
    {
        printf("%d %d\n",h,w);
        for(int i=0;i<w;i++)
        {
            for(int j=h-1;j>=0;j--)
            {
                printf("%d ",a[j][i]);
            }
            printf("\n");
        }
    }
    else if((r%4==3&&c=='R')||(r%4==1&&c=='L'))
    {
        printf("%d %d\n",h,w);
        for(int i=w-1;i>=0;i--)
        {
            for(int j=0;j<h;j++)
            {
                printf("%d ",a[j][i]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("%d %d\n",w,h);
        for(int i=h-1;i>=0;i--)
        {
            for(int j=w-1;j>=0;j--)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}