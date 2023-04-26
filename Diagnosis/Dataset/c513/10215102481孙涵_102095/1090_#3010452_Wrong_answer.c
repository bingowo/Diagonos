#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	long long n,result;
	double x,y;
	while(scanf("%lld",&n) != 0 && scanf("%lld",&n) != EOF){
		x=n*log10(n);
		y=(long long)x;
		x=x-y;
		result=(long long)pow(10.0,x);
		printf("%d\n",result);
	}
	return 0;
}