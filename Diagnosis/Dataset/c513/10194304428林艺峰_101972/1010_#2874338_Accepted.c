#include<stdio.h>
#include<string.h>
int num[5000<<1];
char n[510];
int main(){
	scanf("%s", &n);
	int i, j, len_n = strlen(n), l, end = 3;
	for(i = 0; i < 3; ++i)	num[i] = 0;
	num[3] = 1;
	l = len_n;
	for(i = end + 10; i > end; --i){
		num[i] = l % 2;
		l /= 2; 
	}
	end += 10;
	l = len_n;
	for(i = 0; i < (l / 3) * 3; i += 3){
		int a = 0;
		for(j = i; j < i + 3; ++j){
			a = a * 10 + n[j] - '0';
		}
		for(j = end + 10; j > end; --j){
			num[j] = a % 2;
			a = a / 2;
		}
		end += 10;
	}
	if(len_n % 3 == 1){
		int a = n[len_n-1] - '0';
		for(i = end + 4; i > end; --i){
			num[i] = a % 2;
			a /= 2;
		}
		end += 4;
	}
	else if(len_n % 3 == 2){
		int a = (n[len_n-2] - '0') * 10 + n[len_n-1] - '0';
		for(i = end + 7; i > end; --i){
			num[i] = a % 2;
			a /= 2;
		}
		end += 7;
	}
	for(i = 0; i <= end; ++i)	printf("%d", num[i]); 
	return 0;
}