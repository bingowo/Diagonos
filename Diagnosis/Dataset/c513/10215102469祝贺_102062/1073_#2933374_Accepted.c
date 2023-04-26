#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

 long long dp[20][10];//最高位，最高位的数字，所有位数字和对1~9求模
unsigned long long dfs(int pos,int sum,int limit,int num[]){
    if(pos==-1){
        if(sum%9==0)return 0;
        else return 1;
    }
    if(dp[pos][sum%9]!=-1 && limit==0) return dp[pos][sum%9];
    unsigned long long ret=0;
    int t=(limit?num[pos]:8);
    for(int i=0;i<=t;i++){
        ret+=dfs(pos-1,sum+i,(i==t?limit:0),num);
    }
    if(!limit){
        dp[pos][sum%9]=ret;
    }
    return ret;
}
int main()
{
    unsigned long long x,y;scanf("%llu%llu",&x,&y);
    int n1[19],n2[19],size1=0,size2=0;
    for(int i=0;i<20;i++){
        for(int j=0;j<10;j++)
            dp[i][j]=-1;
    }
    for(;x!=0;size1++,x/=10)n1[size1]=x%10;
    for(;y!=0;size2++,y/=10)n2[size2]=y%10;
    size1--;size2--;
    unsigned long long a1=dfs(size1,0,1,n1),
    a2=dfs(size2,0,1,n2);
    printf("%llu",a2-a1+1);
    return 0;
}