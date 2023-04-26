#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[101][4];
int c[20];
int main()
{
    int w,h;
    scanf("%d %d",&w,&h);
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int x=0;
    for(int i=1;i<h-1;i++)
    {
        for(int j=1;j<w-1;j++)
        {
            x=a[i][j];
            int k=0;
            if(a[i-1][j-1]>=x) c[k++]=1;
            else c[k++]=0;
            if(a[i-1][j]>=x) c[k++]=1;
            else c[k++]=0;
            if(a[i-1][j+1]>=x) c[k++]=1;
            else c[k++]=0;
            if(a[i][j+1]>=x) c[k++]=1;
            else c[k++]=0;
            if(a[i+1][j+1]>=x) c[k++]=1;
            else c[k++]=0;
            if(a[i+1][j]>=x) c[k++]=1;
            else c[k++]=0;
            if(a[i+1][j-1]>=x) c[k++]=1;
            else c[k++]=0;
            if(a[i][j-1]>=x) c[k++]=1;
            else c[k++]=0;
            for(int m=k;m<k+8;m++)
            {
                c[m]=c[m-8];
            }
            int min=255;
            for(int m=0;m<8;m++)
            {
                 int ans=0;
                 for(int n=m;n<m+8;n++)
                {
                    ans=ans*2+c[n];
                }
                if(ans<=min) min=ans;
            }
            if(j==w-2) printf("%d",min);
            else printf("%d ",min);
        }
        if(i!=h-2) printf("\n");
    }
    return 0;
}
