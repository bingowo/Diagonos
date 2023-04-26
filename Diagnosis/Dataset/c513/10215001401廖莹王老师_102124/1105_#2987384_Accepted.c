#include <stdio.h>
#include <stdlib.h>
int p[100][100],re[100][100];
int jisuan(int m,int n)
{
    int i=0,j=0,k=0,l=0,w=0,sum=0;
    int q[8]={0};
    for(i=m-1;i<=m+1;i++)
    {
        if(i==m-1)
        {  for(j=n-1;j<=n+1;j++)
        {if(p[i][j]<p[m][n]){q[k]=0;k++;}
           else if(p[i][j]>=p[m][n]){q[k]=1;k++;}
        }

        }
        else if(i==m)
        {   j=n+1;
           if(p[i][j]<p[m][n]){q[k]=0;k++;}
           else if(p[i][j]>=p[m][n]){q[k]=1;k++;}
        }
         else
        {  for(j=n+1;j>=n-1;j--)
            {
           if(p[i][j]<p[m][n]){q[k]=0;k++;}
           else if(p[i][j]>=p[m][n]){q[k]=1;k++;}
            }
            if(p[m][n-1]<p[m][n])q[k]=0;
           else if(p[m][n-1]>=p[m][n])q[k]=1;

        }
    }
    for(i=0;i<8;i++)
    {   w=0;
        for(j=i;j<8;j++){w=w*2+q[j];}
        for(l=0;l<i;l++){w=w*2+q[l];}
        if(i==0)sum=w;
        else{if(w<sum)sum=w;}
    }
    return sum;
}
int main()
{
    int h=0,w=0,i=0,j=0;
    memset(p,0,sizeof(p));memset(re,0,sizeof(re));
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)scanf("%d",&p[i][j]);
    }
    for(i=1;i<h-1;i++)
    {
        for(j=1;j<w-1;j++){re[i][j]=jisuan(i,j);}
    }
      for(i=1;i<h-1;i++)
    {
        for(j=1;j<w-1;j++)printf("%d ",re[i][j]);
        printf("\n");
    }
    return 0;
}
