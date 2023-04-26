#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

int main()
{
    int w,h,D,num,c=0;
    scanf("%d %d %d %c",&w,&h,&D,&c);
    num = D/90;
    num %= 4;
    if (c=='L') num = (4-num)%4;
    int array[200][200]={};
    int brray[200][200]={};
    for (int i=0;i<h;i++)
        for (int j=0;j<w;j++)
            scanf("%d",&array[i][j]);
    if (num%2==0) printf("%d %d\n",w,h);
    else printf("%d %d\n",h,w);
    if (num==0)
    {
        for (int i=0;i<h;i++)
        {
            for (int j=0;j<w;j++)
            {
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }
    }
    else if (num==1)
    {
        for (int i=0;i<w;i++)
        {
            for (int j=h-1;j>=0;j--)
            {
                printf("%d ",array[j][i]);
            }
            printf("\n");
        }
    }
    else if (num==2)
    {
        for (int i=h-1;i>=0;i--)
        {
            for (int j=w-1;j>=0;j--)
            {
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }
    }
    else if (num==3)
    {
        for (int i=w-1;i>=0;i--)
        {
            for (int j=0;j<h;j++)
            {
                printf("%d ",array[j][i]);
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}