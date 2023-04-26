#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str{
	char string[110];
	int l, step;
}a[100010];
int cmp(const void *a, const void *b){
	const struct str *pa = a, *pb = b;
	if((*pa).l < (*pb).l)	return 1;
	else	return -1;
}
int main(){
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%s", a[i].string);
		a[i].l = strlen(a[i].string);
	}
	qsort(a, n, sizeof(a[0]), cmp);
	for(i = 0; i < n; ++i){
		char character = a[i].string[0], new_str[110];
		int len = 0;
		for(j = 1; j <= a[i].l; ++j){
			if(a[i].string[j] == character)	a[i].step += 1;
			else{
				new_str[len++] = character;
				character = a[i].string[j];
			}
		}
		new_str[len++] = 0;
		strcpy(a[i].string, new_str);
	}
	int flag = 1;
	for(i = 1; i < n; ++i){
		if(strcmp(a[i].string, a[0].string) != 0){
			printf("-1");
			flag = 0;
		}
	}
	if(flag){
		printf("%d", a[0].step - a[n].step);
	}
	return 0;
}