#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct strnum{
	int num, flag;
	char str[35];
}a[110];
int cmp(const void *a, const void *b){
	const struct strnum *pa = a, *pb = b;
	if((*pa).flag && (*pb).flag)	return (*pa).num - (*pb).num;
	if((*pa).flag || (*pb).flag){
		if((*pa).flag)	return 1;
		else return -1;
	}
	return strcmp((*pa).str, (*pb).str);
}
int main(){
	int len = 0, i;
	while(scanf("%s", &a[len].str) != EOF){
		for(i = 0; i < strlen(a[len].str); ++i){
			if(a[len].str[i] >= '0' && a[len].str[i] <= '9'){
				a[len].num = a[len].num * 10 + a[len].str[i] - '0';
				a[len].flag = 1;
			}
		}
		len += 1;
	}
	qsort(a, len, sizeof(a[0]), cmp);
	for(i = 0; i < len; ++i)	printf("%s ", a[i].str);
	return 0;
}