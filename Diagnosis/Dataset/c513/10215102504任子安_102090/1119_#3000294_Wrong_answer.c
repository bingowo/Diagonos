#include <stdio.h>

int main()
{
	long long dis;
	int num;
	long long k,s;
	double ans = 0;
	scanf("%lld %d",&dis,&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lld %lld",&k,&s);
		if((dis-k)/s>ans)
		{
			ans = (dis-k)/s;
		}
	}
	printf("%.6lf",dis/ans);
	return 0;
}