#include <stdio.h>


int main()
{
	int T;
	scanf("%d",&T);
	int i;
	int n;
	unsigned long long num[74];
	num[0]=0;
	num[1]=1;
	num[2]=1;
	for (i=0;i<T;i++){
		scanf("%d",&n);
		printf("case #%d:\n",i);
		for (int j=3;j<74;j++){
			num[j]=num[j-1]+num[j-2]+num[j-3];
		}
		printf("%llu\n",num[n]);
		
	}
	return 0;
}