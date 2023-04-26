#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[510];
int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", &str);
		printf("case #%d:\n", i);
		int l = strlen(str);
		char character = str[0], len = 1;
		for(j = 1; j < l; ++j){
			if(len == 255){
				printf("%d%c", len, character);
				len = 0;
			}
			if(character != str[j]){
				printf("%d%c", len, character);
				character = str[j];
				len = 1;
			}
			else if(character == str[j]){
				len += 1;
			}
		}
		if(len != 0)	printf("%d%c", len, character);
		printf("\n");
	}
	return 0;
}