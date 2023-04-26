#include<stdio.h>
#include<math.h>
int main()
{
	double m,n,j,k;
	int i;
	while(1)
	{
	    scanf("%lf",&k);
	    if(k==0) break;
	    else{
		m=modf(k*1.0*log10(k*1.0),&j);
		m=modf(pow((double)10,m),&j);
		printf("%d\n",(int)j);
	    }
	}
	return 0;
}