#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char cha[27], str1[20000];
int key[27];
struct word{
	char str[25];
}t[110];
char to(char a){
	if(a >= 'a' && a <= 'z')	return a - 'a' + 'A';
	else return a;
}
int cmp(const void *a, const void *b){
	const struct word *pa = a, *pb = b;
	int len = 0, i;
	for(i = 0; ((*pa).str[i] && (*pb).str[i]); ++i){
		len += 1;
		if(to((*pa).str[i]) != to((*pb).str[i])){
			return key[to((*pa).str[i])-'A'] - key[to((*pb).str[i])-'A'];
		}
	}
	if((*pa).str[len] == 0)	return -1;
	return 1;
}
int main(){
	int i;
	while(scanf("%s", &cha)){
		int num = 0, len = 0;
		for(i = 0; i < strlen(cha); ++i)	key[cha[i]-'A'] = i;
		gets(str1);
		gets(str1);
		for(i = 0; i < strlen(str1); ++i){
			if(str1[i] == ' '){
				t[num++].str[len] = 0;
				len = 0;
			}
			else{
				t[num].str[len++] = str1[i];
			}
		}
		t[num++].str[len] = 0;
		qsort(t, num, sizeof(t[0]), cmp);
		for(i = 0; i < num; ++i){
			printf("%s ",t[i].str);
		}
		printf("\n");
	}
	return 0;
}