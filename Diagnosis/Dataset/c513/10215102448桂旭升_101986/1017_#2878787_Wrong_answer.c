#include <stdio.h>
#include <string.h>
int buffer[51] = {0};
long long digit[51] = {0};
char str[51] = {'\0'};

void luo1(int len){
	int i;long long res = 0;
	res = digit[50];
	for(i = 50; i >= 0; i--){
		if(digit[i - 1] >= digit[i])res += digit[i - 1];
		else res -= digit[i - 1];
	}
	printf("%lld", res);
} 
void luo2(int blen, int max, int seat){
	int i = 50;//printf("%d\n", max);
	long long local;
	local = buffer[i];
	for(;i >= 0; i--){//printf("%d\n", buffer[i]);
		if(buffer[i - 1] >= buffer[i])local += buffer[i - 1];
		else local -= buffer[i - 1];
	}
	for(i = 0; i < max; i++){
		local *= 1000;
	}
	digit[seat] = local;
} 
int main() { 
	int num, i = 1, len, max, j = 0, seat, blen;
	scanf("%s", &str); len = strlen(str);
	for(i = 0; i < len; i++){
		if(str[i] == '('){
			num++; max = num; seat = i;
		}
		if(str[i] == ')'){
			num--;
		}
		if(num != 0){
			if(str[i] == 'I')buffer[j++] = 1;
			if(str[i] == 'V')buffer[j++] = 5;
			if(str[i] == 'X')buffer[j++] = 10;
			if(str[i] == 'L')buffer[j++] = 50;
			if(str[i] == 'C')buffer[j++] = 100;
			if(str[i] == 'D')buffer[j++] = 500;
			if(str[i] == 'M')buffer[j++] = 1000;
			str[i] = '0'; blen++;
		}
		//printf("%s\n", str);printf("%d\n", num);
	}
	if(max == 0){
		for(i = 0; i < len; i++){
			if(str[i] == 'I')digit[i] = 1;
			if(str[i] == 'V')digit[i] = 5;
			if(str[i] == 'X')digit[i] = 10;
			if(str[i] == 'L')digit[i] = 50;
			if(str[i] == 'C')digit[i] = 100;
			if(str[i] == 'D')digit[i] = 500;
			if(str[i] == 'M')digit[i] = 1000;
		}
		luo1(len);
	}
	else{
		for(i = 0; i < len; i++){
			if(str[i] == '0')digit[i] = 0;
			if(str[i] == 'I')digit[i] = 1;
			if(str[i] == 'V')digit[i] = 5;
			if(str[i] == 'X')digit[i] = 10;
			if(str[i] == 'L')digit[i] = 50;
			if(str[i] == 'C')digit[i] = 100;
			if(str[i] == 'D')digit[i] = 500;
			if(str[i] == 'M')digit[i] = 1000;
		}
		luo2(blen, max, seat);
		luo1(len);
	}
	return 0;
}
