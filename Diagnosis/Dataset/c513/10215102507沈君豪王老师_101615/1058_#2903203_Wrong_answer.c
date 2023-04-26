#include <stdio.h>
#define N 100000
int main(void)
{
	char c, s[N];
	int ps = 0;
	int line = 0;
	while((c = getchar()) != EOF){
		if(c == '\n'){
			line ++;
		}
		if(line > 28){
			s[ps ++] = c;
		}
	}
	s[ps] = '\0';
	printf("%s", s);
	
	return 0;	
}