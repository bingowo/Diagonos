#include <stdio.h>
#include <stdlib.h>
int a[250][250]={0};
int f[250][250]={0};
int zuoshang(int n,int m, int k)
{
    int i=0,sum=0,x=0,y=0,r=0,count=0;
    for(x=0;x<n;x++)
    {
        for(y=0;y<m;y++)
        {    sum=a[x][y];
            for(r=1;x-r>=0 && y-r>=0;r++)
            {   int d=0,p=0;d=y-r;p=y;
                sum=sum+f[x-r][p]-f[x-r][d-1];
                 if(sum>=k)count++;
            }

        }
    }
    return count;
}
int youshang(int n,int m, int k)
{
    int i=0,sum=0,x=0,y=0,r=0,count=0;
    for(x=0;x<n;x++)
    {
        for(y=0;y<m;y++)
        {    sum=a[x][y];
            for(r=1;x-r>=0 && y+r<m;r++)
            {   int d=0,p=0;d=y+r;p=y;
                sum=sum+f[x-r][d]-f[x-r][p]+a[x-r][y];
                 if(sum>=k)count++;
            }

        }
    }
    return count;
}
int youxia(int n,int m, int k)
{
    int i=0,sum=0,x=0,y=0,r=0,count=0;
    for(x=0;x<n;x++)
    {
        for(y=0;y<m;y++)
        {    sum=a[x][y];
            for(r=1;x+r<n && y+r<m;r++)
            {   int d=0,p=0;d=y+r;p=y;
                sum=sum+f[x+r][d]-f[x+r][p]+a[x+r][y];
                 if(sum>=k)count++;
            }

        }
    }
    return count;
}
int zuoxia(int n,int m, int k)
{
    int i=0,sum=0,x=0,y=0,r=0,count=0;
    for(x=0;x<n;x++)
    {
        for(y=0;y<m;y++)
        {    sum=a[x][y];
            for(r=1;x+r<n && y-r>=0;r++)
            {   int d=0,p=0;d=y-r;p=y;
                sum=sum+f[x+r][p]-f[x+r][d]+a[x+r][d];
                 if(sum>=k)count++;
            }

        }
    }
    return count;
}
int main()
{
    int  n,m,k,i,j;
    int  count;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {   f[i][0]=a[i][0];
        for(j=1;j<m;j++){f[i][j]=f[i][j-1]+a[i][j];}
    }
    int count1=0,count2=0,count3=0,count4=0;
    count1=zuoxia(n,m,k);
    count2=zuoshang(n,m,k);
    count3=youxia(n,m,k);
    count4=youshang(n,m,k);
    count=count1+count2+count3+count4;
    printf("%d\n",count);

    return 0;
}
