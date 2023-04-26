#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int light[10][10], op[10][10];
int main(){
	int t, i, j, k;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		for(j = 1; j <= 3; ++j){
			for(k = 1; k <= 3; ++k){
				light[j][k] = 1;
			}
		}
		for(j = 1; j <= 3; ++j){
			for(k = 1; k <= 3; ++k){
				scanf("%d", &op[j][k]);
				if(op[j][k] % 2 == 1){
					light[j][k] = !light[j][k];
					light[j-1][k] = !light[j-1][k];
					light[j+1][k] = !light[j+1][k];
					light[j][k-1] = !light[j][k-1];
					light[j][k+1] = !light[j][k+1];
				}
			}
		}
		printf("case #%d:\n", i);
		for(j = 1; j <= 3; ++j){
			for(k = 1; k <= 3; ++k){
				printf("%d ",light[j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}