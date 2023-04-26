#include <stdio.h>
#include <math.h>

int main(void) 
{
	int n;
	scanf("%d", &n);
	while(n){
		double n_ = n * log10(n);
		double f = modf(n_, 0);
		int a = (int)pow(10, f);
		printf("%d\n", a);
			
		scanf("%d", &n);
	}
	
	return 0;
}