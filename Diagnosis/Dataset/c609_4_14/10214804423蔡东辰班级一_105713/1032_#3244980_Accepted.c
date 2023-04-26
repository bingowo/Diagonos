#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int cmp(const void* a ,const void* b){
	return *((int*)b) - *((int*)a);
}
int main(){
	int cnt = 0;
	char c;
	char L[51];
	scanf("%s", L);
	int len = strlen(L);
	int result = 1;
	int result_list[50]={0};
	for(int i = 0; i < len; i++){
		if(i==0){
			result_list[cnt++] = 1;	
			continue;
		}
		if(L[i] == '-' &&  L[i-1]=='|'){
			result++;				
		}
		else if(L[i] == '|' &&  L[i-1]=='-'){
			result++;
		}
		else{
			result_list[cnt++] = result;
			result = 1;
		}
	}
	result_list[cnt++] = result;
	qsort(result_list, cnt, sizeof(int), cmp);
	printf("%d", result_list[0]);
	return 0;
}