#include <stdio.h>

int main(void)
{
	char s[51];
	scanf("%s", s);
	char *p1, *p2;
	p1 = s, p2 = s + 1;
	int count = 1 , max = 1;
	while(*p2){
		if(*p2 != *p1){
			count ++;
		}else{
			if(count > max){
				max = count;
			}
			count = 1;
		}
		p2 ++;
		p1 ++;
	}
	if(count > max){
		max = count;
	}
	printf("%d", max);
	
	return 0;
}