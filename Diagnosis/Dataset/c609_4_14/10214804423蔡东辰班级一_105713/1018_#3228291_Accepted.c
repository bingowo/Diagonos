#include <stdio.h>
#include <stdlib.h>
static int cmp(const void* a, const void* b);
int main(){
	int n, temp;
	long long min = 0;
	scanf("%d", &n);
	int* array = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		array[i] = temp;
	}
	qsort(array, n, sizeof(int), cmp);
	for(int i = 0; i < n; i+=2){
		min += array[i+1] - array[i];
	}
	printf("%lld", min);
	return 0;
}
static int cmp(const void* a, const void* b){
	return *((int*)a) - *((int*)b);
}