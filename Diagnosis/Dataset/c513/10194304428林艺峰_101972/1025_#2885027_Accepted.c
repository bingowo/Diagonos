#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct c{
	char str[30];
	int num;
}s[110];
int flag[26];
int cmp(const void *a, const void *b){
	const struct c *pa = a, *pb = b;
	if((*pa).num != (*pb).num)	return (*pb).num - (*pa).num;
	return strcmp((*pa).str, (*pb).str);
}
int main(){
	int t, n, i, j, k, ans;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		for(j = 0; j < n; ++j)	scanf("%s", s[j].str);
		for(j = 0; j < n; ++j){
			ans = 0;
			for(k = 0; k < 26; ++k)	flag[k] = 0;
			for(k = 0; k < strlen(s[j].str); ++k)	flag[s[j].str[k]-'A'] = 1;
			for(k = 0; k < 26; ++k){
				if(flag[k])	ans += 1;
			}
			s[j].num = ans;
		}
		qsort(s, n, sizeof(s[0]), cmp);
		printf("case #%d:\n", i);
		for(j = 0; j < n; ++j)	printf("%s\n", s[j].str);
	}
	return 0;
}