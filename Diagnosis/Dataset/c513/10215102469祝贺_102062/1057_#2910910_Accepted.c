#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char word[1010];
char before[1010];
char after[1010];
int bsp=0,asp=0;
int main(){
	scanf("%s",word);
	char alpha=toupper(word[0]);
	char c=alpha;
	for(int i=1;i<strlen(word);i++){
		char b=toupper(word[i]);
		if(b>=c){
			before[bsp++]=b;
			c=b;
		}
		else if(b<c){
			after[asp++]=b;
		}
	}
	for(int i=bsp-1;i>=0;i--){
		printf("%c",before[i]);
	}
	printf("%c",alpha);
	for(int i=0;i<asp;i++){
		printf("%c",after[i]);
	}
	return 0;
}