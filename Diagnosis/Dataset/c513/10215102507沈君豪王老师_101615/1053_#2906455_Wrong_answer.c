#include <stdio.h>
#include <string.h>
#include <ctype.h>

void spoit(char info[][50], char s[])
{
	char *p1 = s, *p2 = s;
	int i = 0;
	while(*p2){
		if(*p2 == ','){
			memmove(info[i], p1, p2 - p1);
			info[i][p2 - p1] - '\0';
			i ++;
			p2 ++;
			p1 = p2;
		}
		p2 ++;
	}
	memmove(info[i], p1, p2 - p1);
	info[i][p2 - p1] - '\0';
}

int verify(char s[])
{
	char *p = s + 1;
	int code = *p;
	int number = 0;
	p ++;
	while(*p != '*'){
		code ^= *p;
		p ++;
	}
	p ++;
	while(*p){
		number = number * 16 + ((isalpha(*p)) ? (*p - 'A') : (*p - '0'));
		p ++;
	}
	return code == number;
}

int main(void)
{
	char s[100];
	scanf("%s", s);
	while(strcmp(s, "END") != 0){
		char info[50][50];
		int isValid = 1;
		int h = 0, m = 0, second = 0;
		spoit(info, s);
		if(strcmp(info[2], "A") != 0 || strcmp(info[0], "$GPRMC") != 0 || !verify(s)){
			isValid = 0;
		}
		if(isValid){
			h = (info[1][0] - '0') * 10 + (info[1][1] - '0');
			m = (info[1][2] - '0') * 10 + (info[1][3] - '0');
			second = (info[1][4] - '0') * 10 +(info[1][5] - '0');
			h = (h + 8) % 24;
			printf("%02d:%02d:%02d\n", h, m, second);
		}
		scanf("%s", s);
	}
	
	return 0;
}