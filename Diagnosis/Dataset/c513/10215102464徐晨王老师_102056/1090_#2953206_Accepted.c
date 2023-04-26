#include <stdio.h>
#include <math.h>

int main(void) 
{
	int n;
	scanf("%d", &n);
	while(n){
		double nn= n * log10(n);
		int nnn=(int)nn;
		double f = nn-nnn;
		int a = (int)pow(10, f);
		printf("%d\n", a);
		scanf("%d", &n);
	}
	
	return 0;
}