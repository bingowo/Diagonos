#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 10007
int num[105];
long long dp[105][10];

long long dfs(int pos,int sta,int lim)
{
    if(pos==-1)
    {
        if(sta!=0)
            return 1;
        else
            return 0;
    }
    if(!lim && dp[pos][sta]!=-1)
        return dp[pos][sta];
    int up=(lim==1?num[pos]:9);
    long long tmp=0;
    for(int i=0;i<=up;i++)
    {
        if(i==9)
            continue;
        tmp+=dfs(pos-1,(i+sta)%9,lim && i==num[pos]);
    }
    //printf("%d %d %lld\n",pos,sta,tmp);
    if(!lim)
        dp[pos][sta]=tmp;
    return tmp;
}

long long solve(long long val)
{
    if(val==0)
        return 0;
    int cnt=0;
    while(val)
    {
        num[cnt++]=val%10; //记录各位的值
        val/=10;
    }
    return dfs(cnt-1,0,1);
}
int main()
{
    long long L,R;  //求区间内个数的时候，往往是得出从0到端点的值，再作差
    for(int i=0;i<100;i++)
        for(int j=0;j<10;j++)
            dp[i][j]=-1;
    //solve(10);
    scanf("%lld%lld",&L,&R);
    printf("%lld\n",solve(R)-solve(L-1));
    return 0;
}

