#include <stdio.h>

int main()
{
	long long dis;
	int num;
	long long k,s;
	double ans=0;
	scanf("%lld %d",&dis,&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lld %lld",&k,&s);
		if((k-dis)/s>ans)
		{
			ans = (k-dis)/s;
		}
	}
	printf("%.6lf",k/ans);
	return 0;
}