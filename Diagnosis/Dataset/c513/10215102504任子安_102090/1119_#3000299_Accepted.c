#include <stdio.h>

int main()
{
	long long dis;
	int num;
	double k,s;
	double ans = 0;
	scanf("%lld %d",&dis,&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lf %lf",&k,&s);
		if((dis-k)/s>ans)
		{
			ans = (dis-k)/s;
		}
	}
	printf("%.6lf",dis/ans);
	return 0;
}