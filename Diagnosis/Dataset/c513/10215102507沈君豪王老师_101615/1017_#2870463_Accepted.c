#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef long long int lli;

int ReadRoman(char c)
{
	int ret;
	switch(c){
		case 'I':	ret = 1;	break;
		case 'V':	ret = 5;	break;
		case 'X':	ret = 10;	break;
		case 'L':	ret = 50;	break;
		case 'C':	ret = 100;	break;
		case 'D':	ret = 500;	break;
		case 'M':	ret = 1000;	break;
	}
	
	return ret;
}

int isMinus(lli n)
{
	int ret = 0;
	if(n == 1 || n % 5 == 0){
		ret = 1;
	}
	
	return ret;
}

int main(void)
{
	char s[60];
	lli num[60], index = 0, multi = 1, temp = 0, res = 0;
	scanf("%s", s);
	char *p = s; 
	while(*p){
		if(isalpha(*p)){
			num[index ++] = ReadRoman(*p) * multi;
		}else if(*p == '('){
			multi *= 1000;
		}else if(*p == ')'){
			multi /= 1000;
		}
		p ++;
	}
	for(int i = 0 ; i < index; i++){
		if(i != index - 1 && isMinus(num[i]) && num[i] < num[i + 1]){
			res -= num[i];
		}else{
			res += num[i];
		}
	}
	printf("%lld", res);
	
	
	return 0;
}