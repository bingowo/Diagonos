#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
   int n,m,k;
   scanf("%d %d %d",&n,&m,&k);
   int a[n][m];
   int cnt=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
        scanf("%d",&a[i][j]);
   }
    int min=m<n?m:n;
    int y[205][205]={0},x[205][205]={0};
    for(int i=0;i<n;i++)
    {
        x[i][0]=0;
        for(int j=1;j<=m;j++)
        {
            x[i][j]=x[i][j-1]+a[i][j-1];

        }
    }
     for(int i=0;i<m;i++)
    {
        y[0][i]=0;
        for(int j=1;j<=n;j++)
        {
            y[j][i]=y[j-1][i]+a[j-1][i];
        }
    }
     /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
            printf("%d %d %d\n",x[i][j],i,j);
        printf("\n");
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<=n;j++)
            printf("%d %d %d\n",y[j][i],j,i);
        printf("\n");
    }*/
    //左上角
    int temp=0;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++)
   {
       for(int len=2;len<=min;len++)
       {
           int tmp1=i,tmp2=j;
           int ans=0;
           for(int k=len;k>=1;k--)
           {
               ans=ans+x[tmp1][tmp2+k]-x[tmp1][tmp2];
               tmp1++;
           }
          // printf("%d",ans);
           if(ans>=k)
                 cnt++;
       }
   }
   //右上角开始
   for(int i=0;i<n-1;i++)
        for(int j=m-1;j>0;j--)
   {
       for(int len=2;len<=min;len++)
       {
           int tmp1=i,tmp2=j;
           int ans=0;
           for(int k=len;k>=1;k--)
           {
               ans=ans+x[tmp1][tmp2+1]-x[tmp1][tmp2-k+1];
               tmp1++;
               //printf("%d\n",ans);
           }
           //printf("%d",ans);
           if(ans>=k)
                 cnt++;
       }
   }
   //左下角

    for(int i=n-1;i>0;i--)
        for(int j=0;j<m-1;j++)
   {
       for(int len=2;len<=min;len++)
       {
           int tmp1=i,tmp2=j;
           int ans=0;
           for(int k=len;k>=1;k--)
           {
               ans=ans+x[tmp1][tmp2+k]-x[tmp1][tmp2];
               tmp1--;
           }
          // printf("%d",ans);
           if(ans>=k)
                 cnt++;
       }
   }
   //右下角开始
   for(int i=n-1;i>0;i--)
        for(int j=m-1;j>0;j--)
   {
       for(int len=2;len<=min;len++)
       {
           int tmp1=i,tmp2=j;
           int ans=0;
           for(int k=len;k>=1;k--)
           {
               ans=ans+x[tmp1][tmp2+1]-x[tmp1][tmp2-k+1];
               tmp1--;
               //printf("%d\n",ans);
           }
           //printf("%d",ans);
           if(ans>=k)
                 cnt++;
       }
   }
   printf("%d",cnt);
}
