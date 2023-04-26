#include<stdio.h>
#include<stdlib.h>
char a[10];
int num[110];
int cmp1(const void *a, const void *b){
	if(*(int*)a < *(int*)b)	return -1;
	else return 1;
}
int cmp2(const void *a, const void *b){
	if(*(int*)a > *(int*)b)	return -1;
	else return 1;
}
int main(){
	int k = 0, ans = 0, i;
	scanf("%s", &a);
	while(scanf("%d", &num[k]) != EOF){
		k += 1; 
	}
	if(a[0] == 'A')	qsort(num, k, sizeof(num[0]), cmp1);
	else	qsort(num, k, sizeof(num[0]), cmp2);
	for(i = 0; i < k; ++i){
		if(ans != num[i]){
			printf("%d ", num[i]);
			ans = num[i];
		}
	}
	return 0;
}