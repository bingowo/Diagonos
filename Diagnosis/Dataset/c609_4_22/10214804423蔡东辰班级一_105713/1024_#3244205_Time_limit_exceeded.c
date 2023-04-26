#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char ymd[11];
	char time[6];
	int size;
	wchar_t name[190];
}F;
void input(F* array, int i);
static int cmpN(const void* a, const void*b);
static int cmpS(const void* a, const void* b);
static int cmpT(const void* a, const void* b);
int main(){
	int n;
	char c;
	scanf("%d", &n);
	while(1){
		int len  = n;
		F* array = (F*)malloc(n*sizeof(F));
		for(int i = 0; i < n; i++){
			input(array, i);
		}
		char order[5];
		scanf("%s", order);
		scanf("%s", order);
		if(order[1] == 'N'){
			qsort(array, len, sizeof(F), cmpN);
		}
		else if(order[1] == 'S'){
			qsort(array, len, sizeof(F), cmpS);
		}
		else if(order[1] == 'T'){
			qsort(array, len, sizeof(F), cmpT);
		}
		for(int i = 0; i < len; i++){
			printf("%s %s", array[i].ymd, array[i].time);
			printf("%17d ", array[i].size);
			wprintf(L"%s\n", array[i].name);
		}
		scanf("%d", &n);
		if(n!=0){
			printf("\n");
		}
		else{
			break;
		}
		free(array);
	}
	return 0;
}
void input(F* array, int i){
	scanf("%s", array[i].ymd);
	scanf("%s", array[i].time);
	scanf("%d", &array[i].size);
	wscanf(L"%s", array[i].name);
//	array[i].name[wcslen(array[i].name)] = '\0';
}
static int cmpN(const void* a, const void* b){
	F x = *((F*)a);
	F y = *((F*)b);
	if(wcscmp(x.name, y.name)==0){
		return x.size - y.size;
	}
	return wcscmp(x.name, y.name);
}
static int cmpS(const void* a, const void* b){
	F x = *((F*)a);
	F y = *((F*)b);
	return x.size - y.size;
}
static int cmpT(const void* a, const void* b){
	F x = *((F*)a);
	F y = *((F*)b);
	if(strcmp(x.ymd, y.ymd) == 0){
		return strcmp(x.time, y.time);
	}
	return strcmp(x.ymd, y.ymd);
}
