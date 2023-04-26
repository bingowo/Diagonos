#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int w,h;
    scanf("%d%d",&w,&h);
    int a[100][100];
    int b[99][99];
    int c[8];
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++)
            scanf("%d",&a[i][j]);
    for (int i=1; i<h-1; i++)
        for (int j=1; j<w-1; j++)
        {
            int num=0;
            if (a[i-1][j-1]<a[i][j]) c[num++]=0;
            else c[num++]=1;
            if (a[i-1][j]<a[i][j]) c[num++]=0;
            else c[num++]=1;
            if (a[i-1][j+1]<a[i][j]) c[num++]=0;
            else c[num++]=1;
            if (a[i][j+1]<a[i][j]) c[num++]=0;
            else c[num++]=1;
            if (a[i+1][j+1]<a[i][j]) c[num++]=0;
            else c[num++]=1;
            if (a[i+1][j]<a[i][j]) c[num++]=0;
            else c[num++]=1;
            if (a[i+1][j-1]<a[i][j]) c[num++]=0;
            else c[num++]=1;
            if (a[i][j-1]<a[i][j]) c[num++]=0;
            else c[num++]=1;
            int max=0;
            for (int k=0;k<8;k++)
                max=max*2+c[k];

            for (int k=1;k<8;k++){
                int count=0;
                for (int l=0;l<8;l++) count=count*2+c[(k+l)%8];
                if (count<max)max=count;
            }
            if (j!=w-2) printf("%d ",max);
            else printf("%d\n",max);

    }
return 0;
}
