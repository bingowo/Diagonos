#include <stdio.h>
#include <stdlib.h>
int d[3][3],p[3][3];
void caozuo(int m,int n)
{
    d[m][n]=(d[m][n]+1)%2;
    if(m!=0){d[m-1][n]=(d[m-1][n]+1)%2;}
    if(m!=2){d[m+1][n]=(d[m+1][n]+1)%2;}
    if(n!=0){d[m][n-1]=(d[m][n-1]+1)%2;}
    if(n!=2){d[m][n+1]=(d[m][n+1]+1)%2;}
    return;
}
void jisuan(int h)
{
    int i=0,j=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++){d[i][j]=1;scanf("%d",&p[i][j]);}
    }
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(p[i][j]%2==0)continue;
            else {caozuo(i,j);}
        }
    }
    printf("case #%d:\n",h);
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
          printf("%d ",d[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
    return 0;
}
