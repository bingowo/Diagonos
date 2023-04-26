/*
Created by Shizumu on 2022/2/28.  
	这里使用了类似桶排序的方式（由于只有26个字母，这很方便） 
*/
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