
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	char c = getchar();
	for(int i = 0 ; i < t; i ++){
		int AlphaMap[26] = {0}, index = 0;
		char s[210];
		gets(s);
		char *p = s;
		while(*p){
			if(isalpha(*p)){
				AlphaMap[*p - 'A'] += 1;
			}
			p ++;
		}
		p = s;
		printf("case #%d:\n", i);
		for(; AlphaMap[index] == 0; index ++);
		while(*p){
			if(isalpha(*p)){
				*p = index + 'A';
				AlphaMap[index] --;
				for(; AlphaMap[index] == 0; index ++);
			}
			p ++;
		}
		printf("%s\n", s);
		
	}
	
	return 0; 
}
