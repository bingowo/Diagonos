#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long ll;
#define M 210
#define MOD 1000000007
void getdp(char *s)
{
    int i,j,k,len,sum;
    long long ans;
    len=strlen(s);
    int dp[120][210]={1};            //dp[i][j]存的是到第i位截止，前面的算式的和为j的 可能的表达式个数
    for(i=0;i<len;i++)
    {
        sum=0;
        for(j=i;j<len;j++)
        {
            //sum=sum*10+(s[j]-'0');
            sum=(sum*10+(s[j]-'0'))%210;        //可证，在进制小于M（210）的时候，都是可行的
            for(k=0;k<210;k++)
            {
                //dp[j+1][(k+sum)%210]+=dp[i][k];
                dp[j+1][(k+sum)%210]=(dp[j+1][(k+sum)%210]+dp[i][k])%MOD;
                if(i) dp[j+1][(k-sum+210)%210]=(dp[j+1][(k-sum+210)%210]+dp[i][k])%MOD;
            }
        }
    }
    ans=0;
    for(k=0;k<210;k++)
    {
        if(k%2==0||k%3==0||k%5==0||k%7==0)  ans+=dp[len][k];
    }
    printf("%d\n",ans%MOD);
}
int main()
{
    int T,i;
    char s[120];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        getdp(s);
    }
    return 0;
}