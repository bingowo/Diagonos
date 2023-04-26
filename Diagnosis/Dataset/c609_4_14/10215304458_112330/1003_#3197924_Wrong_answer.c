#include<stdio.h>
int main(){
	int t,i,j,ans[40];
	long long n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		i=0;
		while(n){
			ans[i++]=n%2333;
			n/=2333;
		}
		for(j=i-1;~j;--j) printf("%d ",ans[j]);
		printf("\n");
	}
    return 0;
}