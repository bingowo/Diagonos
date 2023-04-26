#include<stdio.h>
#include<stdlib.h>
int num[10];
int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		for(j = 8; j >= 0; --j){
			scanf("%d", &num[j]);
		}
		printf("case #%d:\n", i);
		int flag = 0;
		for(j = 8; j >= 0; --j){
			if(num[j] == 0 && j != 0){
				continue;
			}
			else if(num[j] == -1 && j != 0){
				printf("-");
			}
			else if(num[j] == 1 && j != 0){
				if(flag){
					printf("+");
				}
			}
			else if(num[j] == 0 && j == 0){
				if(!flag){
					printf("0");
				}
				break;
			}
			else if(num[j] == -1 && j == 0){
				printf("-1");
				break;
			}
			else if(num[j] == 1 && j == 0){
				if(!flag){
					printf("1");
				}
				if(flag){
					printf("+1");
				}
				break;
			}
			else{
				if(num[j] < 0){
					printf("%d", num[j]);
				}
				else{
					printf("+%d", num[j]);
				}
			}
			if(j != 1 && j != 0){
				printf("x^%d", j);
				flag = 1;
			}
			else if(j == 1){
				printf("x");
				flag = 1;
			}
		}
		printf("\n");
	}
	return 0;
}