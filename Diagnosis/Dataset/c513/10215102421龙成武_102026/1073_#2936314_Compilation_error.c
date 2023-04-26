#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long int
ll dp[8][10];
void getDp()
{
    int i,j,k;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(i=1; i<=7; i++)
    {
        for(j=0; j<=9; j++)
        {
            if(j==4)
            {
                dp[i][j]=0;
            }
            else if(j==6)
            {
                for(k=0; k<=9; k++)
                {
                    if(k!=2)
                    {
                        dp[i][j]+=dp[i-1][k];
                    }
                }
            }
            else
            {
                for(k=0; k<=9; k++)
                {
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
    }
}
int a[20];
ll solve(int n)
{
    int len=0;///len代表位数
    int i,j;
    while(n)
    {
        a[++len]=n%10;///ai代表着每位数
        n/=10;
    }
    a[len+1]=0;///终止
    ll ans=0;
    for(i=len; i>=1; i--)///倒序
    {
        for(j=0; j<a[i]; j++)
        {
            if(j==4||(a[i+1]==6&&j==2))///不要62和4
            {
                continue;
            }
            else
            {
                ans+=dp[i][j];
            }
        }
        if(a[i]==4)///最高位是4或者最高位是6次高位是2就直接停止，后面的数已经包含在dp数组中了
            break;
        if(a[i+1]==6&&a[i]==2)
            break;
    }
    return ans;
}
int main()
{
    getDp();
    int n,m;
    ll ans1,ans2,ans;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0||n==0)
        {
            break;
        }
        ans1=solve(m);
        ans2=solve(n+1);
        ans=ans2-ans1;
        printf("%lld\n",ans);
    }
}