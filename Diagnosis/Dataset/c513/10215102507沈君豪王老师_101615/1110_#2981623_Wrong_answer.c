#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char s[100];
	scanf("%s", s);
	char *p = s, c;
	int isLeft = 1;
	int num = 0, coe = 0;
	int t = 0, sgn = 1;
	while(*p){
		if(isdigit(*p)){
			while(*p && isdigit(*p)){
				t = t * 10 + (*p - '0');
				p ++;
			}
		}else if(*p == '+'){
			if(t != 0 ){
				num += isLeft * sgn * t;
				t = 0, sgn = 1;
			}else{
				if(isalpha(*(p + 1))){
					coe += 1;
					p += 2;
				}else{
					sgn = 1;
					p ++;
				}				
			}
		}else if(*p == '-'){
			if(t != 0 ){
				num += isLeft * sgn * t;
				t = 0, sgn = 1;
			}else{
				if(isalpha(*(p + 1))){
					coe -= 1;
					p += 2;
				}else{
					sgn = -1;
					p ++;
				}				
			}
		}else if(isalpha(*p)){
			if(t == 0){
				coe += isLeft * sgn * 1;
			}else{
				coe += isLeft * sgn * t;
			}
			t = 0, c = *p;
			p ++;
		}else if(*p == '='){
			if(t != 0 ){
				num += isLeft * sgn * t;
				t = 0, sgn = 1;
			}
			isLeft = -1;
			p ++;
		}
	}
	if(t != 0){
		num += isLeft * sgn * t;
	}
	printf("%c=%.3lf", c, -1 * (double)num / (double)coe);
	
	return 0;
}