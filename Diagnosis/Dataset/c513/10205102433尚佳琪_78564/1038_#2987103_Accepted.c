#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int temp=0;
    int bz=k,ans=0;
    //**
    //*(此为基准点)
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            temp=a[i][j];
            //printf("%d******\n",temp);
            for(int r=1;i-r>=0&&j+r<m;r++)
            {
                int miny=j;
                int maxy=j+r;
                for(int k=miny;k<=maxy;k++)
                    temp=temp+a[i-r][k];
                if(temp>=bz)ans++;
              //  printf("%d\\\\",temp);
            }
        }
    }
    //**
    // *(以此为基准点加)
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            temp=a[i][j];
            for(int r=1;i-r>=0&&j-r>=0;r++)
            {
                int miny=j-r;
                int maxy=j;
                for(int k=miny;k<=maxy;k++)
                    temp=temp+a[i-r][k];
                if(temp>=bz)ans++;
            }
        }
    }
    //*(此为基准点)
    //**
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            temp=a[i][j];
            for(int r=1;i+r<n&&j+r<m;r++)
            {
                int miny=j;
                int maxy=j+r;
                for(int k=miny;k<=maxy;k++)
                    temp=temp+a[i+r][k];
                if(temp>=bz)ans++;
              //    printf("%d\\\",temp);
            }
        }
    }
    // *(此为基准点)
    //**
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            temp=a[i][j];
            for(int r=1;i+r<n&&j-r>=0;r++)
            {
                int miny=j-r;
                int maxy=j;
                for(int k=miny;k<=maxy;k++)
                    temp=temp+a[i+r][k];
                if(temp>=bz)ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
