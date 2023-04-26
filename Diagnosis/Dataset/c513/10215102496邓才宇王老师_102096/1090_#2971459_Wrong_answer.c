
#include<stdio.h>
#include<math.h>
int main()
{
	double m,n,j,k;
	int i;
	while(scanf("%lf",&k)!=EOF)
	{
		m=modf(k*1.0*log10(k*1.0),&j);
		m=modf(pow((double)10,m),&j);
		printf("%d\n",(int)j);
	}
	return 0;
}