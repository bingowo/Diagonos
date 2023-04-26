#include<stdio.h>
#include<math.h>
long long pow1(int n){
	long long ans=1;
	if(n==0) return ans;
	else for(int v=1;v<=n;v++) ans*=2;
	return ans;
	
}
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",v);
		printf("%lld\n",pow1(n)) ;
		
	}
	return 0;
}