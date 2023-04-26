#include<stdio.h>
int main()
{
	int d,n;
	scanf("%d%d",&d,&n);
	double max = 0;
	double s,v,r;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&s,&v);
		r = (d-s)/v;
		if(r>max)
			max = r;
	}
	printf("%.6f",d/max);
	return 0;
}