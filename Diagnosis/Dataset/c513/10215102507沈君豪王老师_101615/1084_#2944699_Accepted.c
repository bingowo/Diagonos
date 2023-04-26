#include <stdio.h>
#include <math.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int input;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &input);
		printf("case #%d:\n%.0f\n", i, pow(2, input));
	}
		
	return 0;
}