#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000000007
char s[1001] = {'\0'};
	
int main(){ 
	int i = 0, n, m, len, t, j, k;
	double a;
	scanf("%s", &t);
	while(1){
		scanf("%lf", &a);
		if(a == 0)break;
		else if(a == 1)printf("1");
		else{
			a = a*log10(a);
			a = a - (long long)a;
			a = pow(10.0, a);
			n = (int)a;
			printf("%d", n);
		}
		
		printf("\n");
	}
	return 0;
}