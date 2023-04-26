#include<stdio.h>

long long f(int n){
	static long long m[50]={0};
	if(n<0)return 0;
	if(m[n]==0){
		if(n!=0)
			m[n]=f(n-1)+f(n-2)+f(n-3)+f(n-4);
		else m[n]=1;
	}
	return m[n];
}

int main(){
	int i,T,n;
	scanf("%d",&T);
	for(i=0;i<T-1;i++){
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%lld\n",f(n));
	}
	printf("case #%d:\n",T-1);
	scanf("%d",&n);
	printf("%lld\n",f(n));
	return 0;
}