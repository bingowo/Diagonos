#include<stdio.h>
#include<string.h>
char B[33];
int f(char *p){
	int num, flag1 = 0, flag2 = 0;long long res = 0, small = 0, wide = 1;
	if(*p == '2')flag1 = -1;
	while(*p != '.' && *p){
		if(*p == '2')num = -1;
		if(*p == '1')num = 1;
		if(*p == '0')num = 0;
		res = res*3 + num;
		p++;
	}
	if(*p == '.'){
		p++;small = 0;
		if(*p == '2')flag2 = -1;
		while(*p){
			if(*p == '2')num = -1;
			if(*p == '1')num = 1;
			if(*p == '0')num = 0;
			small = small*3 + num;
			wide *= 3;
			p++;
		}
		if(res == 0)printf("%lld %lld", small, wide);
		else{
			if(flag1*flag2 > 0){
				small = small*flag2;
			}
			else{
				if(small < 0){
					res = res - 1;
					small = wide + small;
				}
				if(res < 0){
					res = res + 1;
					small = wide - small;
				}
			}
			printf("%lld", res);
			printf(" %lld %lld", small, wide);
		}
		
	}
	else printf("%lld", res);
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