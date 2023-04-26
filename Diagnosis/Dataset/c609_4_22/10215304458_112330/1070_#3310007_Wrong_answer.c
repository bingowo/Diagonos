#include<stdio.h>
int main(){
	int i,t,n,f[21]={0,1,2},g[21]={0,1,2};
	for(i=3;i<=20;++i){
		f[i]=f[i-1]+g[i-1];
		g[i]=f[i]-g[i-2];
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",f[n]+g[n]);
	}
	return 0;
} 