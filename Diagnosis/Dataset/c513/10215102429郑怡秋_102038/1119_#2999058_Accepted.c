#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	int d;
	scanf("%d",&d);
	int n;
	scanf("%d",&n);
	int k0,s0;
	scanf("%d%d",&k0,&s0);
	double t0=(d-k0)*1.0/s0*1.0;
	if(n==1)
	{
		printf("%.6f\n",d*1.0/t0);
	}
	else{
	for(int i=0;i<n-1;i++)
	{
		int k,s;
		double t;
		scanf("%d%d",&k,&s);
		t=(d-k)*1.0/s*1.0;
		if(t>t0) t0=t;
	}
	printf("%.6f\n",d*1.0/t0);
	}
	return 0;	
}