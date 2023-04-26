#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int array[123];
int order[123];
static int cmp(const void* a ,const void* b){
	char x = *((char*)a);
	char y = *((char*)b);
	if(array[x] == array[y]){
		return order[x] - order[y];
	}
	return array[y] - array[x];
}
int main(){
	int T;
	scanf("%d", &T);
	int j = 0;
	for(int i = 'A'; i <= 'Z'; i++){
		order[i+32] = ++j;
		order[i] = ++j;
	}
	for(int i = 0; i<T; i++){
		char string[101];
		for(char c = 'A'; c<='Z'; c++){
			double temp;
			scanf("%lf", &temp);
			array[c] = (int)(temp*100);
			array[c+32] = array[c];
		}
		scanf("%s", string);
		int len = strlen(string);
		qsort(string, len, sizeof(char), cmp);
		printf("case #%d:\n%s\n", i, string);
	}
	return 0;
}