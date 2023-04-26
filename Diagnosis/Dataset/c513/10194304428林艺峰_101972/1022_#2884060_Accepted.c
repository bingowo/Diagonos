#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b){
	const char *pa = *((char **)a), *pb = *((char **)b);
	int i, la = 0, lb = 0;
	for(i = 0; *(pa+i); ++i)	if(*(pa + i) == '@')	la = i;
	for(i = 0; *(pb+i); ++i)	if(*(pb + i) == '@')	lb = i;
	if(strcmp(pa + la + 1, pb + lb + 1) == 0)	return -strcmp(pa, pb);
	else return strcmp(pa + la + 1, pb + lb + 1);
}
int main(){
	int n, i;
	scanf("%d", &n);
	char **p = (char **)malloc(sizeof(char *) * n), s[1000010];
	for(i = 0; i < n; ++i){
		scanf("%s", &s);
		p[i] = (char *)malloc(strlen(s) + 1);
		strcpy(p[i], s);
	}
	qsort(p, n, sizeof(p[0]), cmp);
	for(i = 0; i < n; ++i){
		printf("%s\n", *(p+i));
		free(*(p+i));
	}
	free(p);
	return 0;
}