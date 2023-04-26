#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[20], character[26], characters[26];
int flag[52];
void print(int len, int begin, int k){
	int i;
	if(k > 0){
		for(i = 0; i < k; ++i){
			printf("%c", characters[i]);
		}
		printf("\n");
	}
	if(k == len || begin == len){
		return;
	}
	for(i = begin; i < len; ++i){
		characters[k] = character[i];
		print(len, i + 1, k + 1);
	}
	return;
}
int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", &str);
		int l = strlen(str), len = 0;
		for(j = 0; j < 26; ++j){	flag[j] = 0; flag[j+26] = 0;}
		for(j = 0; j < l; ++j){
			if(str[j] >= 'A' && str[j] <= 'Z')	flag[str[j] - 'A'] = 1;
			if(str[j] >= 'a' && str[j] <= 'z')	flag[str[j] - 'a' + 26] = 1;
		}
		for(j = 0; j < 26; ++j)	if(flag[j])	character[len++] = 'A' + j;
		for(j = 0; j < 26; ++j)	if(flag[j+26])	character[len++] = 'a' + j;
		printf("case #%d:\n", i);
		print(len, 0, 0);
	}
}