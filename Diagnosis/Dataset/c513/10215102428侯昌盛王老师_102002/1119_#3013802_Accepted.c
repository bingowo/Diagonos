#include <stdio.h>

int main()
{
	int d,i;
	scanf("%d",&d);
	int n;
	double max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int k,s;
		scanf("%d %d",&k,&s);
		int res;
		res=d-k;
		//printf("%d\n",res);
		if(res*1.0/s>max) 
		{
			max=res*1.0/s;
		}
		
	}
	double max_v;
	max_v=d*1.0/max;
	printf("%.6lf\n",max_v);
	return 0;
}