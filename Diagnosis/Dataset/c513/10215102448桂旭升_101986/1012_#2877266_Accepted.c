#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long xi[2] = {0};
char s[100] = {'\0'};
char xu[100] = {'\0'};
char shi[100] = {'\0'};
char ans[100] = {'\0'};
void reverse(char s[]) {
    int  R = strlen(s);
	if (R  <= 1)
		return ;
	else {
		char tmp = s[0];
		s[0] = s[R-1];
		s[R - 1] = '\0';
		reverse(s+1);
		s[R - 1] = tmp;
	}
}
void on(){
	strcat(shi, s); 
	xu[0] = '0';
}
void oi(){
	int len = strlen(s), i;
	shi[0] = '0';
	if(s[0] == '-' && len <= 2)s[1] = '1';
	else if(len == 1)s[0] = '1';
	else s[len - 1] = '\0';
	strcat(xu, s);
}
void ni(){
	int len = strlen(s), i = 0, j = 1;
	if(s[0] == '-'){
		shi[0] = '-'; i++;
	}
	for(; i < len; i++){
		if(s[i] == '-' || s[i] == '+')break;
		shi[i] = s[i];
	}
	xu[0] = s[i]; i++;
	if(i == len - 1)xu[1] = '1';
	else{
		for(; i < len - 1; i++){
			xu[j] = s[i]; j++;
		}
	} 
	
}
int main() { 
	int j = 0, i = 2, len, wide = 1, flag = 0, remark = 0, num1 = 0, num2 = 0;
	long long int qr=0,qi=0;
	long long int a,b;
	long long r = 0;
	scanf("%s", &s);len = strlen(s);
	if(s[0] == '0')ans[0] = '0';
	if(s[len - 1] == 'i')num1++; 
	for(i = len - 1 - num1; i > -1 && (s[i] != '-' && s[i] != '+'); i--);
	if(i == -1){
		if(num1 == 0) on();
		else oi();
	}
	else{
		if(num1 == 0) on();
		else if(i == 0) oi();
		else ni();
	}
	a = atoll(shi);b = atoll(xu);
	while(a != 0 || b != 0){
		r = ((a + b) % 2) == 0? 0 : 1; ans[j] = r + '0'; j++;//printf("a = %lld b = %lld", a, b);printf("r = %lld\n", r);
		qi = -1 * ((a + b) - r)/2;
		qr = qi + b;
		a = qr; b = qi;
	}
	reverse(ans);
	printf("%s\n", ans);
	return 0;
}
