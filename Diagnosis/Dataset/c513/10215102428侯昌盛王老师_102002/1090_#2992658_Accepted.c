#include <stdio.h>
#include <math.h>
int main()
{
	long long int n;
	while(~scanf("%lld",&n)!=EOF&&n!=0)
	{
		double a,z;
		a=n*log10(n);
	
		long long int res;
		res=(long long)a;
		z=a-res;
		int result;
		result=pow(10.0,z);
		printf("%d\n",result); 
	}
	return 0;
}