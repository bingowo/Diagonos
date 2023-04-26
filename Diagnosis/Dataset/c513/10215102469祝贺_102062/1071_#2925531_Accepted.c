#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
long long dp[1010][1010];

long long pow(int a,int n){
	long long ans=a;int i=1;
	if(n==0)return 1;
	if(n==1)return a%10007;
	while(i*2<=n){
		ans=ans*ans%10007;
		i*=2;
	}
	for(;i<n;i++){
		ans=ans*a%10007;
	}
	return ans;
}
int main()
{	
	int pro;scanf("%d",&pro);
	for(int i=0;i<=1000;i++){
		dp[i][1]=i;dp[i][i]=1;
		dp[i][0]=1;
	}
	for(int i=3;i<=1000;i++){
		for(int j=2;j<i;j++){
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%10007;
		}
	}

	for(int index=0;index<pro;index++){
		unsigned long long a,b,k,n,m;
		scanf("%llu%llu%llu%llu%llu",&a,&b,&k,&n,&m);
		long long a1=dp[k][n];
		long long a2=pow(a,n)*pow(b,m)%10007;
		printf("case #%d:\n%d\n",index,a1*a2%10007);
	}
	return 0;
}