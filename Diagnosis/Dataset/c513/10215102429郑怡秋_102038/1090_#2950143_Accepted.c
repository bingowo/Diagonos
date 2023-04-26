#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d",&n);
	double a,b;
	int ans;
	while(n)
	{
		a=n*log10(n);
		b=a-(int)a;
		ans=pow(10,b);
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}