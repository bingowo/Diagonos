#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double character[26];
char str[110];
int toupper(int x){
	if(x >= 'a' && x <= 'z')	return x - 'a' + 'A';
	else	return x;
}
int cmp(const void *a, const void *b){
	const char *pa = a, *pb = b;
	if(character[toupper(*pa) - 'A'] == character[toupper(*pb) - 'A']){
		return (*pb) - (*pa);
	}
	if(character[toupper(*pa) - 'A'] < character[toupper(*pb) - 'A'])	return 1;
	return -1;
}
int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		for(j = 0; j < 26; ++j)	scanf("%lf", &character[j]);
		scanf("%s", &str);
		int l = strlen(str);
		qsort(str, l, sizeof(str[0]), cmp);
		str[l] = 0;
		printf("case #%d:\n%s\n", i, str);
	}
	return 0;
}