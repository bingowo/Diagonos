#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void *p1,const void *p2)
{
    return (int*)p1-(int*)p2;
}
int to(int *p)
{
    int l=0;
    for(int i=0;i<8;i++)
        l=l*2+p[i];
    return l;
}
int main()
{
    int W,H;
    scanf("%d %d",&W,&H);
    int s[W+1][H+1];
    int ans[W-1][H-1];
    for(int i=0;i<W;i++)
    {
        for(int j=0;j<H;j++)
            scanf("%d",&s[i][j]);
    }
    for(int i=1;i<W-1;i++)
    {
        int a[17]={0};
        for(int j=1;j<H-1;j++)
        {
            if(s[i-1][j-1]>=s[i][j]) a[0]=1;
            else a[0]=0;
            if(s[i][j-1]>=s[i][j]) a[1]=1;
            else a[1]=0;
            if(s[i+1][j-1]>=s[i][j]) a[2]=1;
            else a[2]=0;
            if(s[i+1][j]>=s[i][j]) a[3]=1;
            else a[3]=0;
            if(s[i+1][j+1]>=s[i][j]) a[4]=1;
            else a[4]=0;
            if(s[i][j+1]>=s[i][j]) a[5]=1;
            else a[5]=0;
            if(s[i-1][j+1]>=s[i][j]) a[6]=1;
            else a[6]=0;
            if(s[i-1][j]>=s[i][j]) a[7]=1;
            else a[7]=0;
            for(int q=8;q<16;q++)
            {
                a[q]=a[q-8];
            }
            int b[9][9];
            int c[9]={0};
            for(int w=0;w<8;w++)
            {
                int flag=0;
                for(int e=w;e<w+8;e++)
                {
                    b[w][flag++]=a[e];
                }
                c[w]=to(b[w]);
            }
            qsort(c,8,4,cmp);
            ans[i-1][j-1]=c[0];
        }
    }
    for(int z=0;z<H-2;z++)
    {
        for(int x=0;x<W-2;x++)
            printf("%d ",ans[x][z]);
        printf("\n");
    }
}
