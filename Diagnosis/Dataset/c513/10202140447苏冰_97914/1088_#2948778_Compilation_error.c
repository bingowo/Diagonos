#include<stdio.h>
#include<string.h>
#define N 95
long long dp[2020][2020];
long long C(int n,int k)
{
    if(k==0 || k==n) return 1;
    if(dp[n][k]!=0) return dp[n][k];
    return dp[n][k]=C(n-1,k-1)+C(n-1,k);
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        printf("case #%d:\n",cas);
        long long ans=C(m,n);
        printf("%lld\n",ans);a
    }
}
