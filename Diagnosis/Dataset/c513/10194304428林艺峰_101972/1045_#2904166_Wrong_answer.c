#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str{
	char string[110];
	int l;
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
	if(strstr(a[0].string, a[n-1].string) == 0)	printf("-1");
	else{
	}
	return 0;
}