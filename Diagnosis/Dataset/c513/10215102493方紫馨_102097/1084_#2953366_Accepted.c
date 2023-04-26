#include<stdio.h>
int main()
{
	long long int num[31];
	num[0]=1;num[1]=2;
	for(int i=2;i<31;i++){
		num[i] = num[i-1]*2;
	}
	int T;
	scanf("%d",&T);
	int n;
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%lld\n",num[n]);
	}
	return 0;
}