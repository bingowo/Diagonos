#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long work(int n,int m){
	if(n<m) return 0;
	if(n==m) return 1;
	if(n==m+1) return n;
    else{long long dp[10000]={0};
       dp[m]=0;
       dp[m+1]=1;
	   	for(int i=m+2;i<=n;i++){
    	dp[i]=dp[i-1]+dp[i-2];
		return dp[n]+pow(2,n-m-1);}
		}
    
	
}
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)&&n!=-1&&m!=-1)
	{
		long long ans=work(n,m);
		printf("%lld\n",ans);
		
	}
	
	return 0;
}