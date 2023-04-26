#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	long long int ret[51];
	ret[1]=1,ret[2]=2,ret[3]=4,ret[4]=8,ret[5]=15;
	for(int i=6;i<51;i++){
		ret[i]=ret[i-1]*2-ret[i-5];
	}
	for(int i=0;i<T;i++){
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%lld\n",ret[n]);
	}
	
}