#include <stdio.h>
#include <math.h>
#include <string.h>

void itob(int n/*ÊäÈëÊý*/, char s[]/*Êä³öÊý×é*/, int b/*Ä¿±ê½øÖÆ*/)
{ 
	int i;
	int isMinus = n < 0 ? 1 : 0;
	n = abs(n);
	for(i = 98; n && i; n /= b){
		s[i--] = (((n % b) < 10) ? '0' : ('A' - 10)) + (n % b);
	}
	memmove(s + isMinus, s + i + 1, 99 - i- 1);
	s[99 - i- 1 + isMinus] = '\0';
	if(isMinus){
		s[0] = '-';
	}
}


int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n, r;
		scanf("%d %d", &n, &r);
		int sum = 0;
		if(n == 0){
			sum = 0;
			printf("case #%d:\n0\n", i);
		}else{
			while(n > 0){
				sum += (n % r);
				n /= r;
			}
			char res[100];
			itob(sum, res, r);
			printf("case #%d:\n", i);
			printf("%s\n", res);			
		}

	}

	return 0;
}