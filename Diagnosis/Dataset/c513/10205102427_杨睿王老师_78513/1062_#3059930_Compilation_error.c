#include <bits/stdc++.h>
int main(){
	unsigned long long int a[51];
	for(int u=0;u<51;u++){
		a[u]=0;
	}
	a[0]=1;
	a[1]=2;
	a[2]=4;
	a[3]=8;
	for(int u=4;u<51;u++){
		a[u]=a[u-1]+a[u-2]+a[u-3]+a[u-4];
	}	
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		int n;
		scanf("%d",&n);
		printf("case #%d:\n%llu\n",i,a[n-1]);
	}
	return 0; 
}