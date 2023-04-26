#include <stdio.h>
#include <math.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		long long int k;
		k=pow(2,n);
		printf("%lld\n",k);
	}
}