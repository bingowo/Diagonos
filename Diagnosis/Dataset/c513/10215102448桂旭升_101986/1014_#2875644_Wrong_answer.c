#include<stdio.h>
#include<string.h>
char s[200] = {'\0'};
char res[100] = {'\0'};
long long digit[3] = {0};
void reverse(char s[]){
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
int zhi(){
	int num = 0;long long d = digit[1];
	while(d > 1){
		num++;d /= 3;
	}
	return num;
}
int swap(){
	long long n = digit[0];
	int i = 0, len;
	while(n > 0){
		res[i] = (n%3) + 1 + '0';
		n = n / 3;i++;
	}
	len = strlen(res);
	for(i = 0; i < len; i++){
		if(res[i] >= '3'){
			if(res[i + 1] == '\0')res[i + 1] = '2';
			else res[i + 1] += 1;
			res[i] -= 3;
		}
	}
	reverse(res);
	len = strlen(res);
	for(i = 0; i < len; i++){
		if(res[i] == '0')res[i] = '2';
		else if(res[i] == '1')res[i] = '0';
		else res[i] = '1';
	}
}
int main()
{
    int a, b, t = 0, i = 0, num, len, j = 0;long long re = 0;
    gets(s);len = strlen(s);
    for(i = 0; i < len; i++){
		if(s[i] != ' '){
			re = re * 10 + (s[i] - '0');digit[j] = re;
		}
		else {
			re = 0;j++;
		}
	}
	
    swap();len = strlen(res); b = zhi(); t = len - b;
    if(t <= 0){
    	printf("0.");
    	for(i = 0; i < -1*t; i++){
    		printf("0");
		}
		printf("%s", res);
	}
    if(t > 0 && b != 0){
    	for(i = len - 1; i >= t; i--){
    		res[i + 1] = res[i];
		}
		res[t] = '.';
    	len = strlen(res);
    	for(i = len - 1; i >= t - 1; i--){
    		if(res[i] != '0'){
				res[i + 1] = '\0';break;
			}
    		
		}
		printf("%s", res);
	}
	if(t > 0 && b == 0){
    	printf("%s", res);
	}
}
