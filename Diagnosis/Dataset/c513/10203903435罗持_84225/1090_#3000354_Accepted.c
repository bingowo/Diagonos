#include <stdio.h>
#include <math.h>
int main(void)
{
	int n;
	while(scanf("%d",&n)){
		if(n==0) break;
		double m = n*log10(n);
		m = m-(int)m;
		double x = pow(10,m);
		printf("%d\n",(int)x);
	}
	return 0;
}