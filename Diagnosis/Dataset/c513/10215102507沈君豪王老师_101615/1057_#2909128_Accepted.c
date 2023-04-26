#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int main(void)
{
	int n[2001], index = 0, max = 0;
	memset(n, -1, sizeof(n));
	char c = getchar();
	n[1000] = max = toupper(c);
	while((c = getchar()) != '\n'){
		if(toupper(c) < max){
			for(index = 1000; index < 2001 && n[index] != -1; index ++);
			n[index] = toupper(c);
		}else{
			for(index = 1000; index >= 0 && n[index] != -1 ; index --);
			n[index] = toupper(c);
			max = toupper(c);
		}
	}
	for(index = 0 ; n[index] == -1; index++);
	for(; n[index] != -1; index ++){
		printf("%c", n[index]);
	}
	
	return 0;
}