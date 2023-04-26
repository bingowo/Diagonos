#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
char str1[110], str2[110];
int num1[110], num2[110], ans[110];
int max(int x, int y){
	return x>y?x:y;
}
int main(){
	int t, i, j, len1 = 0, len2 = 0, sum = 0;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s%s", &str1, &str2);
		len1 = 0; len2 = 0; sum = 0;
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
		memset(ans, 0, sizeof(ans));
		int l1 = strlen(str1), l2 = strlen(str2);
		for(j = 0; j < l1; ++j){
			if(str1[j] == ','){
				num1[len1++] = sum;
				sum = 0;
			}
			else{
				sum = sum * 10 + str1[j] - '0';
			}
		}
		num1[len1++] = sum;
		sum = 0;
		for(j = 0; j < l2; ++j){
			if(str2[j] == ','){
				num2[len2++] = sum;
				sum = 0;
			}
			else{
				sum = sum * 10 + str2[j] - '0';
			}
		}
		num2[len2++] = sum;
		sum = 0;
		for(j = 0; j < len1 / 2; ++j){
			int x = num1[j];
			num1[j] = num1[len1 - 1 - j];
			num1[len1 - 1 - j] = x;
		}
		for(j = 0; j < len2 / 2; ++j){
			int x = num2[j];
			num2[j] = num2[len2 - 1 - j];
			num2[len2 - 1 - j] = x;
		}
		int maxn = max(len1, len2), temp = 0;
		for(j = 0; j < maxn; ++j){
			ans[j] = (num1[j] + num2[j] + temp);
			temp = ans[j] / prime[j];
			ans[j] %= prime[j];
		}
		if(temp != 0){
			ans[maxn++] = temp;
		}
		printf("case #%d:\n", i);
		for(j = maxn - 1; j > 0; --j){
			printf("%d,", ans[j]);
		}
		printf("%d\n", ans[0]);
	}
	return 0;
}