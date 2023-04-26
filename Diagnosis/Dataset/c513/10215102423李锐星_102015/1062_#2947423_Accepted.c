#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	int i,n;
	for (i=0;i<T;i++){
		scanf("%d",&n);
		unsigned long long num[50];
		num[0]=1;
		num[1]=2;
		num[2]=4;
		num[3]=8;
		for (int j=4;j<50;j++){
			num[j]=num[j-1]+num[j-2]+num[j-3]+num[j-4];
		}
		printf("case #%d:\n",i);
		printf("%llu\n",num[n-1]);
	}
	return 0;
 } 