#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
	return *(int*)a-*(int*)b;//升序排序
}
int main(){
	int n = 0;//点数
	int inp[100] = {0};
	int sum = 0;
	scanf("%d", &n);
	for(int i = 0;i<n;i++){
		scanf("%d", &inp[i]);
	}
	qsort(inp, n, sizeof(int), cmp);
	for(int i = 1;i<n;i+=2){
		sum += abs(inp[i] - inp[i-1]);
	}
	printf("%d", sum);
	return 0;
}