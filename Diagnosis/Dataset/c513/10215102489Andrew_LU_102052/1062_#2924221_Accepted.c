#include<stdio.h>
int main(){
	int t,n;
	long long ans[55];
	ans[1]=1;
	ans[2]=2;
	ans[3]=4;
	ans[4]=8;
	for(int i=5;i<=50;i++){
		ans[i]=ans[i-1]+ans[i-2]+ans[i-3]+ans[i-4];
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		printf("case #%d:\n%lld\n",i,ans[n]);
	}
}