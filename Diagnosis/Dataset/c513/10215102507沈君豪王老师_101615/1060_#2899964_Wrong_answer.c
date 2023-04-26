#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char s[110];
	scanf("%s", s);
	char *p1 = s, *p2 = s + 1;
	int len = 0;
	while(*p2){
		while(isalpha(*p2) || *p2 == '0'){
			p2 ++;
		}
		p1 = p2;
		while(isdigit(*p2) && *p2){
			p2 ++;
		}
		if(p2 - p1 > len){
			len = p2 - p1;
		}
	}
	printf("%d", len);
	
	return 0;
}