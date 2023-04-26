#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int ans[110], product[110], num[110];
char str[110];
int main(){
	scanf("%s", &str);
	int i, j, l = strlen(str), len = 0, sum = 0, lenp = 0, lenans = 0;
	for(i = 0; i < l; ++i){
		if(str[i] == ','){
			num[len++] = sum;
			sum = 0;
		}
		else{
			sum = sum * 10 + str[i] - '0';
		}
	}
	num[len++] = sum;
	for(i = 0; i < len / 2; ++i){
		int x = num[i];
		num[i] = num[len - 1 - i];
		num[len - 1 - i] = x;
	}
	product[lenp++] = 1;
	for(i = 0; i < len; ++i){
		for(j = 0; j < lenp; ++j){
			ans[j] += product[j] * num[i];
			ans[j+1] += ans[j] / 10;
			ans[j] %= 10;
		}
		int n = 0;
		while(ans[lenp + n] >= 10){
			ans[lenp+n+1] += ans[lenp] /10;
			ans[lenp+n] %= 10;
			n += 1;
		}
		int temp = 0;
		for(j = 0; j < lenp; ++j){
			product[j] = product[j] * prime[i] + temp;
			temp = product[j] / 10;
			product[j] %= 10;
		}
		while(temp){
			product[lenp++] = temp % 10;
			temp /= 10;
		}
	}
	int flag = 0;
	for(i = 109; i >= 0; --i){
		if(flag){
			printf("%d", ans[i]);
		}
		else if(ans[i] != 0){
			printf("%d", ans[i]);
			flag = 1;
		}
	}
	return 0;
}