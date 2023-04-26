#include <stdio.h>
#include <math.h>

int main(void) 
{
	int n;
	scanf("%d", &n);
	while(n){
		double n_ = n * log10(n), i = 0;
		double f = modf(n_, &i);

		int a = (int)pow(10, f);
		printf("%d\n", a);
		scanf("%d", &n);
	}
	
	return 0;
}