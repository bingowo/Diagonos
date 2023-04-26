#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	int m;
	int d;
	int y;
}DATE;
char* M[19] = {"pop", "no", "zip" , "zotz" , "tzec", "xul", 
"yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
void input(DATE* array, int N);
int month_cal(char* m);
static int cmp(const void* a, const void* b);
int main(){
	int T, N;
	scanf("%d", &T);	
	for(int i = 0; i<T; i++){
		scanf("%d", &N);
		DATE* array = (DATE*)malloc(sizeof(DATE) * N);
		input(array, N);
		qsort(array, N, sizeof(DATE), cmp);
		printf("case #%d:\n", i);
		for(int j = 0; j<N; j++){
			printf("%d. %s %d\n", array[j].d, M[array[j].m], array[j].y);
		}
		free(array);
	}
	return 0;
}

void input(DATE* array, int N){
	char c;
	for(int j = 0; j<N; j++){
		scanf("%d", &array[j].d);
		c = getchar();
		char month[7];
		scanf("%s", month);
		array[j].m = month_cal(month);
		scanf("%d", &array[j].y);
	}
}
int month_cal(char* m){
	
	for(int i = 0; i<19; i++){
		if(strcmp(m, M[i]) == 0){
			return i;
		}
	}
}
static int cmp(const void* a, const void* b){
	DATE x = *((DATE*)a);
	DATE y = *((DATE*)b);
	if(x.y == y.y){
		if(x.m == y.m){
			return x.d - y.d;
		}
		return x.m - y.m;
	}
	return x.y - y.y;
}