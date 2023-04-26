#include<stdio.h>
#include<string.h>
char B[33];
int f(char *p){
	int num, res = 0, wide = 1;
	while(*p != '.' && *p){
		if(*p == '2')num = -1;
		if(*p == '1')num = 1;
		if(*p == '0')num = 0;
		res = res*3 + num;
		p++;
	}
	printf("%d", res);
	if(*p == '.'){
		p++;
		while(*p){
			if(*p == '2')num = -1;
			if(*p == '1')num = 1;
			if(*p == '0')num = 0;
			res = res*3 + num;
			wide *= 3;
			p++;
		}
		printf(" %d %d", res, wide);
	}
}

int main()
{
	int t, i;
	char *p;
	scanf("%s", &B);
	p = B;
	f(p); 
	return 0;
}