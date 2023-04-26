#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void judge(int d[])
{
    int max=0,i,j;
    for(i=0;i<8;i++)
    {
        int t=0;
        for(j=0;j<8;j++)
        {
            t=t*2+d[(i+j)%8];
        }
        max=max>t? max:t;
    }
    printf("%d",max);
}

int main()
{
    int W,H;scanf("%d %d",&W,&H);
    int i,j;int a[H][W],d[8];
    for(i=0;i<H;i++)
        for(j=0;j<W;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<H-1;i++)
    {
        for(j=1;j<W-1;j++)
        {
            d[0]=a[i-1][j-1]>=a[i][j]?1:0;
            d[1]=a[i-1][j]>=a[i][j]?1:0;
            d[2]=a[i-1][j+1]>=a[i][j]?1:0;
            d[3]=a[i][j-1]>=a[i][j]?1:0;
            d[4]=a[i][j+1]>=a[i][j]?1:0;
            d[5]=a[i+1][j-1]>=a[i][j]?1:0;
            d[6]=a[i+1][j]>=a[i][j]?1:0;
            d[7]=a[i+1][j+1]>=a[i][j]?1:0;
        }
        judge(d);
        if(j!=W-2)putchar(" ");
        else putchar("\n");
    }
    
}