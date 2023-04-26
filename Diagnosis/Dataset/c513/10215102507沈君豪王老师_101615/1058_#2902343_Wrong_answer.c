#include <stdio.h>
#define N 100000

int main(void)
{
	char c, s[N];
	int isLineComment = 0, isParaComment = 0, isQuote = 0;
	int ps = 0, pbuf = 0;
	while((c = getchar()) != EOF){
		if(c == '/' && !isQuote){
			if(isLineComment != 2 && isParaComment != 3){
				isLineComment ++;
				isParaComment ++;
				if(isLineComment == 2){
					isParaComment = 0;
				}
			}else if(isParaComment == 3){
				isParaComment = 0;
			}
		}else if(c == '*' && !isQuote){
			if(isParaComment == 1){
				isParaComment ++;
				isLineComment = 0;
			}else if(isParaComment == 2){
				isParaComment ++;
			}else{
				s[ps ++] = c;
			}
		}else if(c == '\n'){
			if(isLineComment == 2){
				isLineComment = 0;
			}
			s[ps ++] = '\n';
		}else if(c == '"'){
			if(isQuote == 0){
				isQuote = 1;
			}else{
				isQuote = 0;
			}
			s[ps ++] = '"';
		}else if(isLineComment != 2 && isParaComment != 2){
			s[ps ++] = c;
		}
	}
	printf("%s", s);
	
	return 0;
}