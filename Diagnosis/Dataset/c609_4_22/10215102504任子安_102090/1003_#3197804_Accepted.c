#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		long long int n;
		scanf("%lld",&n);
		int ans[10001] = {0};
		int k = 0;
		do
		{
			ans[k++] = n % 2333;
			n = n / 2333;
		}
		while(n);
		for(k=k-1;k>=0;k--)
		{
			printf("%d ",ans[k]);
		}
		printf("\n");
	}
	return 0;
}