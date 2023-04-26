#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i;
	char s[1000001];
	int number[100]={};
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(number[s[i]-'0'])continue;
		else printf("%c",s[i]);
		number[s[i]-'0']++;
	}
	return 0;
}