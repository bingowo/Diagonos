#include<stdio.h>
int main()
{
	int d,n;
	scanf("%d%d",&d,&n);
	double max=-1;
	double k,s,temp;
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&k,&s);
		temp=(d-k)/s;
		if(temp>max)max=temp;
	}
	printf("%.6f",d/max);
}