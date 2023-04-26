#include <stdio.h>
#include <stdlib.h>
int a,n,m,x;
struct num{
	int aa,cc;
};
struct node{
	struct num shang;
	struct num xia;
	struct num you;
}dp[30];
int main(void)
{
	scanf("%d %d %d %d",&a,&n,&m,&x);
	
	dp[1].shang.aa = 1, dp[1].shang.cc=0;
	dp[1].xia.aa = 0, dp[1].xia.cc=0;
	dp[1].you.aa = 1, dp[1].you.cc=0;
	
	dp[2].shang.aa = 0, dp[2].shang.cc=1;
	dp[2].xia.aa = 0, dp[2].xia.cc=1;
	dp[2].you.aa = 1, dp[2].you.cc=0;
	
	for(int i=3;i<n;i++){
		dp[i].shang.aa = dp[i-1].shang.aa+dp[i-2].shang.aa;
		dp[i].shang.cc = dp[i-1].shang.cc+dp[i-2].shang.cc;
		dp[i].xia.aa = dp[i-1].shang.aa;
		dp[i].xia.cc = dp[i-1].shang.cc;
		dp[i].you.aa = dp[i-1].you.aa+dp[i-2].shang.aa;
		dp[i].you.cc = dp[i-1].you.cc+dp[i-2].shang.cc;
		//printf("%d %da+%dc %da+%dc %da+%dc\n",
		//i,dp[i].shang.aa,dp[i].shang.cc,
		//dp[i].xia.aa,dp[i].xia.cc,
		//dp[i].you.aa,dp[i].you.cc);
	}
	
	struct num res = dp[n-1].you;
	int c = (m-res.aa*a)/res.cc;
	
	int ans = dp[x].you.aa*a+dp[x].you.cc*c;
	printf("%d",ans);
	return 0;
}