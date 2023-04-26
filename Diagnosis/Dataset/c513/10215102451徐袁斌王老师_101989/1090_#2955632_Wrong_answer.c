#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	
	int i,k,t;
	double n,a;
	while(scanf("%lf",&n)!=EOF)
	{
		k=n*log10(n);
		a=pow(10,(n*log10(n))-k);
		printf("%d\n",(int)a);
	}
}