#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
const int MOD=10007;
int PowerMod(int a,int b,int c)
{
    int ans=1;
    a=a%c;
    while(b>0)
    {
        if(b%2==1) ans=(ans*a)%c;
        b=b/2;
        a=(a*a)%c;
    }
    return ans;
}
long long dp[2020][2020];
long long C(int n, int k)
{
	if (k == 0 || k == n) return 1;
	if (dp[n][k]!=0) return dp[n][k];
	return (dp[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % MOD);
}//求组合数
int main()
{
    int T;
    scanf("%d",&T);
    int a,b,k,n,m;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        long long ans=C(k,m);
        //printf("%lld\n",ans);
        ans=ans%MOD;
        int ans1=PowerMod(a,n,MOD);
        int ans2=PowerMod(b,m,MOD);
        printf("case #%d:\n",cas);
        printf("%lld\n",(ans*ans1*ans2)%MOD);
    }
    return 0;
}
