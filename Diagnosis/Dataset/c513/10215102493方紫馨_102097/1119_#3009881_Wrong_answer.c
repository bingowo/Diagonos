#include<stdio.h>
int main()
{
	int d,n;
	scanf("%d%d",&d,&n);
	double max = 0;
	long long s,v,r;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&s,&v);
		r = (d-s)*1.0/v;
		if(r>max)
			max = r;
	}
	printf("%.6f",d/max);
	return 0;
}