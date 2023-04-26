#include<stdio.h>

long long int sum[205][205],A[205][205];
int main()
{
    int n,m,k,i,j,r;
    scanf("%d%d%d",&n,&m,&k);
    long long int ans=0,num=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            scanf("%d",&A[i][j]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            sum[i][j]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            sum[i][j]=sum[i][j-1]+A[i][j];
    }
    //          1
    //右下    1 1
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            num=A[i][j];
            for(r=1;j+r<=m&&i+r<=n;r++)
            {
                num+=sum[i+r][j+r]-sum[i+r][j-1];
                if(num>=k) ans++;
            }
        }
    }
    //          1
    //左下    1 1
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            num=A[i][j];
            for(r=1;j-r>=1&&i+r<=n;r++)
            {
                num+=sum[i+r][j]-sum[i+r][j-1-r];
                if(num>=k) ans++;
            }
        }
    }
    //           11
    //右上       1
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            num=A[i][j];
            for(r=1;i-r>=1&&j+r<=m;r++)
            {
                num+=sum[i-r][j+r]-sum[i-r][j-1];
                if(num>=k) ans++;
            }
        }
    }
    //     11
    //左上 1
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            num=A[i][j];
            for(r=1;i-r>=1&&j-r>=1;r++)
            {
                num+=sum[i-r][j]-sum[i-r][j-r-1];
                if(num>=k) ans++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
