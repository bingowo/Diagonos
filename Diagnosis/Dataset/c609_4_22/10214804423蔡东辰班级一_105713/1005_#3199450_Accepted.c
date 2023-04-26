#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static unsigned powL(char number[], int i, int x);
int main(){
	int T;
	scanf("%d", &T);
	int i = 0;
	while(i++ < T){
		char* s = (char*)malloc(sizeof(char) * 50);
		scanf("%s", s);
		int len = strlen(s);
		int n = powL(s, len-1, 3);
		printf("case #%d:\n%d\n", i-1, n);
		free(s);
	}
	return 0;
	
}
static unsigned powL(char number[], int i, int x){
	if(i==0){
		return (number[i]=='-')? -1 : number[i]-'0';
	}
	unsigned bit = (number[i]=='-')? -1 : number[i]-'0';;
	return bit + x * powL(number, i-1, x);
}