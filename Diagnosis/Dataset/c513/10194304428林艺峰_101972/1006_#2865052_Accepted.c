#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int t, i, j, l, k = 1, sum = 0;
	char str[30];
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", str);
		l = strlen(str);
		k = 1;
		sum = 0;
		for(j = l - 1; j >= 0; --j){
			if(str[j] == '-'){
				sum -= k;
			}
			else if(str[j] == '1'){
				sum += k;
			}
			k *= 3;
		}
		printf("case #%d:\n%d\n", i, sum);
	}
	return 0;
}