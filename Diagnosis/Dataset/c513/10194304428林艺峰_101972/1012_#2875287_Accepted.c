#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_num[110];
char str[110];
int main(){
	scanf("%s", &str);
	int i, len_str = strlen(str), flag = 0, sign = 1, len = 0;
	long long mult = 1, a = 0, b = 0, r = 0, num = 0;
	if(str[len_str-1] == 'i')	flag = 1;
	if(flag){
		for(i = 0; i < len_str; ++i){
			if(i == 0 && str[i] == '-')	sign = -1;
			else if(str[i] == '-'){
				a = sign * num;
				sign = -1;
				num = 0;
			}
			else if(str[i] == '+'){
				a = sign * num;
				sign = 1;
				num = 0;
			}
			else if(str[i] == 'i'){
				if(num == 0)	b = sign * 1;
				else b = sign * num;
			}
			else{
				num = num * 10 + str[i] - '0';
			}
		}
	}
	else{
		for(i = 0; i < len_str; ++i){
			if(i == 0 && str[i] == '-')	sign = -1;
			else{
				num = num * 10 + str[i] - '0';
			}
		}
		a = sign * num;
	}
	if(a == 0 && b == 0)	str[len++] = 0;
	while(a != 0 || b != 0){
		if(((a % 2 + b % 2) == 1) || ((a % 2 + b % 2) == -1))	r = 1;
		else	r = 0;
		str_num[len++] = r;
		long long a1 = (r - a + b) / 2, b1 = (r - a - b) / 2;
		a = a1;
		b = b1;
//		printf("%lld %lld\n",a,b);
	}
	for(i = len - 1; i >= 0; --i)	printf("%d", str_num[i]);
	return 0;
}