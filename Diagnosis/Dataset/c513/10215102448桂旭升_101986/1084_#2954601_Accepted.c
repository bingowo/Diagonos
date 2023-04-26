#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int i, t, n, j, k;
	int result = 1;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		printf("case #%d:\n", i);
		if(n == 0)printf("1");
		else{
			for(j = 0; j < n; j++){
				result *= 2;
			}
			printf("%d", result);
		}
		if(i != n-1)printf("\n");
		result = 1;
	}
    
	return 0;
}

		
	