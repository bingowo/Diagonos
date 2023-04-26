#include <stdio.h>
#include <string.h>
#include <math.h>

void itob(int n, char s[], int b)
{ 
	int i;
	int isMinuse = n < 0 ? 1 : 0;
	n = abs(n);
	for(i = 98; n && i; n /= b){
		s[i--] = (((n % b) < 10) ? '0' : ('A' - 10)) + (n % b);
	}
	memmove(s + isMinuse, s + i + 1, 99 - i- 1);
	s[99 - i- 1 + isMinuse] = '\0';
	if(isMinuse){
		s[0] = '-';
	}
	
}

int main(void)
{
	int t, n, b;
	scanf("%d", &t);
	for(int i = 0; i < t ; i ++){
		char s[100] = {0, };
		scanf("%d %d", &n, &b);
		itob(n, s, b);
		printf("%s\n", s);
	}
	
	return 0;
}