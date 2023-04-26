#include <stdio.h>
#include <stdlib.h>

long long data[205][205];
long long s[205][205];

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            s[i][j]=s[i-1][j]+data[i][j];
        }
    }
    long long ans=0;
    for(int t=1;t<=n;t++)
    {
        for(int p=1;p<=m;p++)
        {
            long long sum=data[t][p];
            for(int r=1;t+r<=n&&p-r>=1;r++)
            {
                sum+=(s[t+r][p-r]-s[t-1][p-r]);
                if(sum>=k) ans++;
            }
            sum=data[t][p];
            for(int r=1;t+r<=n&&p+r<=m;r++)
            {
                sum+=(s[t+r][p+r]-s[t-1][p+r]);
                if(sum>=k) ans++;
            }
            sum=data[t][p];
            for(int r=1;t-r>=1&&p-r>=1;r++)
            {
                sum+=(s[t][p-r]-s[t-r-1][p-r]);
                if(sum>=k) ans++;
            }
            sum=data[t][p];
            for(int r=1;t-r>=1&&p+r<=m;r++)
            {
                sum+=(s[t][p+r]-s[t-r-1][p+r]);
                if(sum>=k) ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
