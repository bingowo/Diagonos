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
     /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
            printf("%d %d %d\n",x[i][j],i,j);
        printf("\n");
    }*/
    //**
    //* 以此形状 每次增加一行
    for(int i=n-1;i>0;i--)
        for(int j=0;j<m-1;j++)
        {
            int s=a[i][j];
            for(int len=2;(i+1-len)>=0&&(j+len)<=m;len++)
            {
                int ly=j;
                int ry=j+len;
                s=s+x[i-(len-1)][ry]-x[i-(len-1)][ly];
                if(s>=k)
                    cnt++;
               // printf("%d ",s);
            }
       }

   //**
   // *以此形状 每次增加一行
   for(int i=n-1;i>0;i--)
        for(int j=m-1;j>0;j--)
        {
            int s=a[i][j];
            for(int len=2;(i+1-len)>=0&&(j+1-len)>=0;len++)
            {
                int ly=j+1-len;
                int ry=j+1;
                s=s+x[i-(len-1)][ry]-x[i-(len-1)][ly];
                if(s>=k)
                    cnt++;
              //  printf("%d ",s);
            }
       }

   //*
   //**
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++)
        {
            int s=a[i][j];
            for(int len=2;(i+len)<=n&&(j+len)<=m;len++)
            {
                int ly=j;
                int ry=j+len;
                s=s+x[i+(len-1)][ry]-x[i+(len-1)][ly];
                if(s>=k)
                    cnt++;
              //  printf("%d ",s);
            }
       }

   // *
   //**
   for(int i=0;i<n-1;i++)
        for(int j=m-1;j>0;j--)
        {
            int s=a[i][j];
            for(int len=2;(i+len)<=n&&(j+1-len)>=0;len++)
            {
                int ly=j+1-len;
                int ry=j+1;
                s=s+x[i+(len-1)][ry]-x[i+(len-1)][ly];
                if(s>=k)
                    cnt++;
                //printf("%d ",s);
            }
       }

   printf("%d",cnt);
}
