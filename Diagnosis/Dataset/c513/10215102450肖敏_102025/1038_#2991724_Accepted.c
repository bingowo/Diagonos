#include <stdio.h>
typedef long long ll;
ll data[205][205];
ll S[205][205];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%lld",&data[i][j]);
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
            S[i][j]=S[i-1][j]+data[i][j];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ll sum=data[i][j];
            for(int x=1;i+x<=n && j-x>=1;x++)//右下
            {
                sum+=(S[i+x][j-x]-S[i-1][j-x]);
                if(sum>=k)
                    ans++;
            }
            sum = data[i][j];
            for(int x=1;i+x<=n&& j+x<=m;x++)//左下
            {
                sum+=(S[i+x][j+x]-S[i-1][j+x]);
                if(sum>=k)
                    ans++;
            }
            sum = data[i][j];
            for(int x=1;i-x>=1 && j+x<=m;x++)//左上
            {
                sum+=(S[i][j+x]-S[i-x-1][j+x]);
                if(sum>=k)
                    ans++;
            }
            sum = data[i][j];
            for(int x=1;i-x>=1 && j-x>=1;x++)//右上
            {
                sum+=(S[i][j-x]-S[i-x-1][j-x]);
                if(sum>=k)
                    ans++;
            }

        }
    }
    printf("%lld\n",ans);
    return 0;
}
