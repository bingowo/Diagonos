#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	int N;
	double n,x;
	while(scanf("%d",&N)&&N!=0)
	{
		n=N; 
		x=modf(n*log10(n),&n);
		x=modf(pow(10.0,x),&n);N=n;
		printf("%d\n",N);
	}
	return 0;
 } 