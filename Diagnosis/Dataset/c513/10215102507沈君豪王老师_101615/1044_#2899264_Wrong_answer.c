#include <stdio.h>
#include <ctype.h>

const int N = 100000;
typedef long long int lli;

int isHexDigit(char c)
{
	int ret = 0;
	if(isdigit(c) || (c >= 'a' && c <= 'f')){
		ret = 1;
	}
	return ret;
}

int main(void)
{
	char s[N + 1];
	scanf("%s", s);
	char *p1 = s, *p2 = p1 + 1;
	lli temp = 0;
	int isValid = 0;
	while(!(*p1 == '0' && *p2 == 'x') && *p1 && *p2){
		p1 = p2 + 1;
		p2 = p1 + 1;
	}
	while(*p1){
		if(isHexDigit(*p1) && !(*p1 == '0' && *p2 == 'x')){
			isValid = 1;
			temp = temp * 16 + (isalpha(*p1) ? (*p1 - 'a' + 10) : (*p1 - '0'));
//			printf("%d", isalpha(*p1) ? (*p1 - 'a' + 10) : (*p1 - '0'));
			p1 ++, p2 ++;
		}else{
			if(temp != 0){
				printf("%lld ", temp);
				temp = 0;
				p1 ++, p2 ++;
			}else{
				p1 ++, p2 ++;
			}
		}
		
	}
	if(!isValid){
		printf("-1");
	}else if(temp != 0){
		printf("%lld", temp);
	}
	return 0;
}
