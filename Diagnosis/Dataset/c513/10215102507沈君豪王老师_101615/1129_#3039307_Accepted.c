#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	char word[10001];
	char c;
	int isReadNumber = 0, i = 0, expand = 0;
	while((c = getchar()) != EOF){
		if(isalpha(c) && !isReadNumber){
			word[i++] = c;
		}else if((isalpha(c) && isReadNumber) || c == '\n'){
			if(!isReadNumber){
				expand = 1;
			}
			isReadNumber = 0;
			word[i] = '\0';
			for(int j = 0 ; j < expand ; j ++){
				printf("%s", word);
			}
			if(isalpha(c)){
				expand = 0;
				i = 0;
				word[i++] = c;
			}else{
				break;
			}
		}
		if(isdigit(c)){
			isReadNumber = 1;
			expand = expand * 10 + (c - '0');
		}
	}
	
	return 0;
}