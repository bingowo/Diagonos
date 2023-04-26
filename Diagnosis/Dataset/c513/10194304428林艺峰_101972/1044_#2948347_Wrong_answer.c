#include<string.h>
#include<stdio.h>
char str[100010];
unsigned int num[50000];
int main(){
	scanf("%s", &str);
	int l = strlen(str), i, len = 0;
	unsigned int sum = 0, value = 1;
	for(i = l - 1; i >= 0; --i){
		if(str[i] == 'x' && str[i-1] == '0' && sum != 0){
			num[len++] = sum;
			sum = 0;
			value = 1;
			i--;
		}
		else if(str[i] >= 'a' && str[i] <= 'f'){
			sum += (str[i] - 'a' + 10) * value;
			value *= 16;
		}
		else if(str[i] >= '0' && str[i] <= '9'){
			sum += (str[i] - '0') * value;
			value *= 16;
		}
		else{
			sum = 0;
			value = 1;
		}
	}
	for(i = len - 1; i >= 0; --i){
		printf("%u ", num[i]);
	}
	return 0;
}