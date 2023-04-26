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
	for(long long i=0;i<y-x;i++){
		tag=0;int carry=0,p=1;mod++;
		do{
			dp[p]++;
			if(dp[p]==10){dp[p]=0;carry=1;}
			else if(dp[p]==9){
				while(dp[p]==9){
					dp[p]=0;dp[p+1]++;
					i+=pow(10,p-1);num-=pow(10,p-1);
					p++;
				}
				tag=0;mod=1;carry=0;
			}
			else carry=0;
			p++;
		}while(carry!=0);
		if(mod==9){mod=0;tag=-1;}
		if(tag==-1)num--;
	}
	printf("%lld",num);
	return 0;
}