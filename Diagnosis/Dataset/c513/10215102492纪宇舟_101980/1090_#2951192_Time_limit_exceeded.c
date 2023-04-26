#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	int n;
	long long x;//14223481
	while(scanf("%d",&n)&&n!=0)
	{
		x=1;
		for(int j=1;j<=n;j++)
		{
			x*=n;
			while(x>=1000)x/=10;
		}
		if(x>=100)x/=100;
		else if(x>=10)x/=10;
		printf("%lld\n",x);
	}
	return 0;
 } 