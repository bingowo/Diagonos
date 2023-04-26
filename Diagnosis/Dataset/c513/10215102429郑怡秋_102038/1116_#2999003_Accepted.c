#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
unsigned long long po(int x)
{
	unsigned long long res=1;
	for(int i=0;i<x;i++)
	{
		res*=2;
	}
	return res;
}


int main()
{
	long long x,y;
	scanf("%lld%lld",&x,&y);
	int sum=0;
	unsigned long long ans=llabs(x)+llabs(y);
	if(ans%2==0&&ans>0) printf("-1");
	else 
	{
		if(ans>po(63)) 
		{
			sum+=64;
		}
		for(int j=0;j<64;j++)
		{
			unsigned long long q=po(j);
			if(ans>=q/2&&ans<q)
			{
				//printf("\n%d %d\n",i,j);
				sum+=j;
				break;
			}
		}
		printf("%d\n",sum);
	}
	
	return 0;
}