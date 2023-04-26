#include <stdio.h>
void rrotate(int (*a)[200],int W,int H)
{
    int b[200][200],i,j;
    for(i = 0;i<H;i++)
    {
        for(j = 0;j<W;j++)
        {
            b[j][H-1-i] = a[i][j];
        }
    }
    for(i = 0;i<W;i++)
    {for(j = 0;j<H;j++)
    a[i][j] = b[i][j];
    }
}
void lrotate(int (*a)[200],int W,int H)
{
    int i,j,b[200][200];
    for(i = 0;i<H;i++)
    {
        for(j = 0;j<W;j++)
        {
            b[W-1-j][i] = a[i][j];
        }
    }
    for(i = 0;i<W;i++)
    {for(j = 0;j<H;j++)
    a[i][j] = b[i][j];
    }
}
int main()
{
    int W,H,D,n,i,j,m;
    char c;
    scanf("%d %d %d %c",&W,&H,&D,&c);
    int a[200][200];
    for(i = 0;i<H;i++)
    {   for(j = 0;j<W;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    n = D/90;
    m = n%4;
    if(c=='R')
    {
       for(i = 1;i<=m;i++)
       {
           if(i%2) rrotate(a,W,H);
           else rrotate(a,H,W);
       }
    }
    else{
        for(i = 1;i<=m;i++)
        {
            if(i%2) lrotate(a,W,H);
            else lrotate(a,H,W);
        }
    }
    if(n%2==1)
    {
        printf("%d %d\n",H,W);
        for(i = 0;i<W;i++)
        {
            for(j = 0;j<H;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    else{
        printf("%d %d\n",W,H);
        for(i = 0;i<H;i++)
        {
            for(j = 0;j<W;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
