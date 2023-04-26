#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	
	long long x,y;
	scanf("%lld %lld",&x,&y);
	long long sum;
	int n=0;
	
	sum=llabs(x)+llabs(y);
	//printf("%\\d",sum);
	if(sum%2==0)
	{
		printf("-1\n");
		goto end;
	}
	long long int sum2=sum;
	while(sum2)
	{
		sum2/=2;
		n++;
	}
	printf("%d\n",n);
	
	
	end:
		return 0;
}