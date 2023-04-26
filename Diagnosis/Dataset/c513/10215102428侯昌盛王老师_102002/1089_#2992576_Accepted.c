#include <stdio.h>
#include <math.h>
#define N 9000
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long long a,sum=1;
		int n,b;
		scanf("%lld %d %d",&a,&b,&n);
		long long int k;
		k=pow(10,n);
		int j=0;
		for(j;j<b;j++) sum=sum*a%k;

		long long int sum2=sum,count=0;
		if(sum2==0) count=1;
		while(sum2)
		{
			sum2/=10;
			count++;
		}
		printf("case #%d:\n",i);
		if(count!=n)
		{
			int e=0;
			for(e;e<n-count;e++) printf("0");
		}
		printf("%lld\n",sum);
	}
	return 0;
}