#include<stdio.h>
#include<string.h>
char B[33];
int f(char *p){
	int num, res = 0, wide = 1, small;
	while(*p != '.' && *p){
		if(*p == '2')num = -1;
		if(*p == '1')num = 1;
		if(*p == '0')num = 0;
		res = res*3 + num;
		p++;
	}
	if(*p == '.'){
		p++;small = 0;
		while(*p){
			if(*p == '2')num = -1;
			if(*p == '1')num = 1;
			if(*p == '0')num = 0;
			small = small*3 + num;
			wide *= 3;
			p++;
		}
		if(small < 0){
			res = res - 1;
			small = wide + small;
		}
		printf("%d", res);
		printf(" %d %d", small, wide);
	}
	else printf("%d", res);
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