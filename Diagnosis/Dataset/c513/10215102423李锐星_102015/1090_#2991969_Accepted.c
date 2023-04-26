#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	double x,y;
	while((scanf("%d",&N))!=EOF&&N!=0){
		x=N*log10(N);
		y=(long long)x;
		x=x-y;
		printf("%d\n",(long long)pow(10.0,x));
	}
	return 0;
}