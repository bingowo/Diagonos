
#include<stdio.h>
#include<math.h>
int main()
{
	double m,n,j,k;
	int i;
	scanf("%lf",&k)；
	while(1)
	{
	    if(k==0) break;
		m=modf(k*1.0*log10(k*1.0),&j);
		m=modf(pow((double)10,m),&j);
		printf("%d\n",(int)j);
		scanf("%lf",&k)；
	}
	return 0;
}