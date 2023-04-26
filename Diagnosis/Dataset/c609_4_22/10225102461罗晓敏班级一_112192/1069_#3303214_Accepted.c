#include <stdio.h>
long long int f(int n){
	int i;
	long long int ret=1;
	for(i=0;i<n;i++){
		ret*=2;
	}
	return ret;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+1&&m+1){
		long long int num[32]={0};
		int i;
		for(i=1;i<=n;i++){
			if(i<m){
				num[i]=0;
			}else if(i==m){
				num[i]=1;
			}else{
				num[i]=2*num[i-1]-num[i-1-m]+f(i-1-m);
			}
		}
		printf("%lld\n",num[n]);	
	}
}