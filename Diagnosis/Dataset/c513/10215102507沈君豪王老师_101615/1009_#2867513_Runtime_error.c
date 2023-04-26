#include <stdio.h>

int CalcuOne(char c)
{
	int n = c;
	int ret = 0;
	while(n > 0){
		if(n % 2 == 1){
			ret ++;
		}
		n /=2;
	}
	
	return ret;
}

int gcd(int a, int b)
{
	int ret, rest = a % b;
	while(rest){
		a = b;
		b = rest;
		rest = a % b;
	}
	ret= b;
	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	char c = getchar();
	for(int i = 0; i < t; i ++){
		char s[121];
		gets(s);
		char *p = s;
		int num = 0, oneNum = 0;
		while(*p){
			num ++;
			oneNum += CalcuOne(*p);
			p ++;
		}
		int multi = gcd(8 * num, oneNum);
		printf("%d/%d\n", oneNum / multi, (8 * num) / multi);
	}
	
	return 0;
}