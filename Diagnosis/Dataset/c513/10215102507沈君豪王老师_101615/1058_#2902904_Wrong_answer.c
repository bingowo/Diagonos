#include <stdio.h>
#define N 100000

int main(void)
{
	char c, s[N];
	int isLineComment = 0, isParaComment = 0, isQuote = 0;
	int ps = 0, pbuf = 0;
	while((c = getchar()) != EOF){
		if(c == '/' && !isQuote && isParaComment != 2){
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
			}else if(isParaComment == 3){
				isParaComment = 3;
			}else{
				s[ps ++] = c;
			}
		}else if(c == '\n'){
			if(isLineComment == 2){
				isLineComment = 0;
				s[ps ++] = '\n';
			}else if(isParaComment >= 2){
				if(isParaComment == 3){
					isParaComment = 2;
				}
			}else{
				s[ps ++] = '\n';
			}
		}else if(c == '"' && !isLineComment && !isParaComment){
			if(isQuote == 0){
				isQuote = 1;
			}else if(isQuote == 1 && s[ps - 1] != 92){
				isQuote = 0;
			}
			s[ps ++] = '"';
		}else if(c == 39 && !isLineComment && !isParaComment){
			if(isQuote == 0){
				isQuote = 2;
			}else if(isQuote == 2 && s[ps - 1] != 92){
				isQuote = 0;
			}
			s[ps ++] = 39;
		}
		else if(isLineComment != 2 && isParaComment != 2){
			s[ps ++] = c;
		}
	}
	s[ps] = '\0';
	printf("%s", s);
	
	return 0;
}