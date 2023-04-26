#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int dp[19];
long long pow(int a,int n){
	long long ans=a;int i=1;
	if(n==0)return 1;
	if(n==1)return a;
	while(i*2<=n){
		ans=ans*ans;
		i*=2;
	}
	for(;i<n;i++){
		ans=ans*a;
	}
	return ans;
}
int main()
{	
	for(int i=0;i<19;i++)dp[i]=0;
	long long x,y;scanf("%lld%lld",&x,&y);
	long long num=y-x+1;
	for(long long t=x,i=1;t!=0;t/=10,i++)dp[i]=t%10;
	int tag=0,mod=x%9;
	int i=0;
	while(i<y-x){
		if(mod>dp[1]){
			dp[1]+=9-mod;i+=9-mod;
			mod=0;
			num-=1;
		}
		else{
			int p=1;
			mod+=9-dp[p];i+=9-dp[p];
			dp[p]=9;
			while(dp[p]>=9){
				if(dp[p]==9){
					dp[p]=0;dp[p+1]++;
					i+=pow(10,p-1);num-=pow(10,p-1);
					mod=1;
					p++;
				}
				else{
					int c=dp[p]/10;
					dp[p]=dp[p]%10;
					dp[p+1]+=c;
					p++;
				}
			}
		}
	}
	printf("%lld",num);
	return 0;
}