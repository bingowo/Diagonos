#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[210];
int cmp(const void *a, const void *b){
	const char *pa = a, *pb = b;
	if(((*pa) >= 'A' && (*pa) <= 'Z') && ((*pb) >= 'A' && (*pb) <= 'Z')){
		if((*pa) > (*pb))	return 1;
		else	return -1;
	}
	return -1;
}
int main(){
	int t, i, j;
	scanf("%d", &t);
	gets(s);
	for(i = 0; i < t; ++i){
		gets(s);
		qsort(s, strlen(s), sizeof(s[0]), cmp);
		for(j = 0; j < strlen(s); ++j)	printf("%c",s[j]);
		printf("\n");
	}
	return 0;
}