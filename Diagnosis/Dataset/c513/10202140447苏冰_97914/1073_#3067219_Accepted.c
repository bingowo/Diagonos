#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[20];//a存放的是数字的每一位
long long dp[20];
//pos表示数字的位数
//limit表示填数字的限制，如果没有限制（limit=0），表示0~9随便填
//如果有限制（limit=1）,0-a[pos],传参时参数值为1，即初始状态有限制
//可选参数：
//pre表示上一位数字是多少
//zero表示前导零是否存在，1表示存在前导零，0表示不存在
//cnt某个数字出现的次数
//sum搜索到当前所有数字的和
long long dfs(int pos,int sum,int limit)
{
    if(pos==-1)
    {
        if(sum%9==0) return 0;
        else return 1;
    }
    if(!limit && dp[pos]!=-1) return dp[pos];
    long long res=0;
    int end=limit?a[pos]:9;
    for(int i=0;i<=end;i++)
    {
        if(i==9) continue;
        res+=dfs(pos-1,sum+i,limit && i==a[pos]);
    }
    if(!limit) dp[pos]=res;
    return res;
}
long long solve(long long x)
{
    memset(dp,-1,sizeof(dp));//要初始化为-1
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,0,1);
}
int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long ans=solve(b)-solve(a-1);
    printf("%lld",ans);
    return 0;
}
