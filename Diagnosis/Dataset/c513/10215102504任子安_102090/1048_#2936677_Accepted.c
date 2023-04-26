#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ReadPoly(int n[], char s[])
{
	char *p = s;
	int sgn, coe, exp;
	int isConst, isMonomial;
	while(*p){
		sgn = 1, coe = 0, exp = 0;
		isConst = 1, isMonomial = 1;
		if(*p == '+' || *p == '-'){
			if(*p == '-'){
				sgn = -1;
			}else{
				sgn = 1;
			}
			p ++;
		}
		if(*p && isdigit(*p)){
			while(*p && isdigit(*p)){
				coe = coe * 10 + (*p - '0');
				p ++;
			}
			coe *= sgn;
		}
		if(*p == 'x'){
			if(coe == 0){
				coe = 1 * sgn;
			}
			isConst = 0;
			p ++;
		}
		if(*p == '^'){
			isMonomial = 0;
			p ++;
		}
		if(*p && isdigit(*p)){
			while(*p && isdigit(*p)){
				exp = exp * 10 + (*p - '0');
				p ++;
			}
		}
		if(isConst){
			n[0] = coe;
		}else if(isMonomial){
			n[1] = coe;
		}else{
			n[exp] = coe;
		}
	}
}


int main(void)
{
	char s1[110], s2[110];
	while(scanf("%s %s", s1, s2) != EOF){
		int poly1[51] = {0}, poly2[51] = {0}, poly[101] = {0};
		ReadPoly(poly1, s1);
		ReadPoly(poly2, s2);
		for(int i = 50 ; i >= 0; i --){
			for(int j = 50 ; j >= 0; j -- ){
				poly[i + j] += poly1[i] * poly2[j]; 
			}
		}
		for(int i = 100; i >= 0; i --){
			if(poly[i] != 0){
				printf("%d ", poly[i]);
			}
		}
		printf("\n");
	}
	return 0;	
} 