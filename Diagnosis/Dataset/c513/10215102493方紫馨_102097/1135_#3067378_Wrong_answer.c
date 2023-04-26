#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	long long num[101];
	num[0]=1;
	num[1]=1;
	num[2]=2;
	num[3]=3;
	for(int i=4;i<=n;i++){
		num[i]=num[i-1]+num[i-2]+num[i-4];
	}	
	printf("%lld",num[n]);
	return 0;
}