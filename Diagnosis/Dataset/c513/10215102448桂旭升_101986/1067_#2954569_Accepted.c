#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int i, t, n, j, k;
	int a0[20];
	int a00[20];
	int a000[20];
	int result[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &t);
		printf("case #%d:\n", i);
		if(t == 0)printf("0");
		else if(t == 1 || t == 2)printf("1");
		else {
			for(j = 0; j < 20; j++){
				a0[j] = 0; a00[j] = 0; a000[j] = 0; result[j] = 0;
			}
			a00[19] = 1; a0[19] = 1;
			for(j = 3; j <= t; j++){
				for(k = 19; k >= 0; k--){//printf("%d\n", a0[19]);
					result[k] = result[k] + a0[k] + a00[k] + a000[k];
					if(result[k] >= 10){
						result[k-1] += result[k]/10; result[k] %= 10;
					}
				}
				for(k = 19; k >= 0; k--){
					a000[k] = a00[k]; a00[k] = a0[k]; a0[k] = result[k]; result[k] = 0;
				}
			}
			j = 0;
			while(a0[j] == 0)j++;
			for(; j < 20; j++){
				printf("%d", a0[j]);
			}
		}
		if(i != n-1)printf("\n");
	}
    
	return 0;
}

		
	