#include<stdio.h>
#include<stdlib.h>
int a[1010], b[1010];
int cmp1(const void *x, const void *y){
	const int *px = x, *py = y;
	return (*px) - (*py);
}
int cmp2(const void *x, const void *y){
	const int *px = x, *py = y;
	return (*py) - (*px);
}
int main(){
	int t, n, i, j, ans = 0;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		for(j = 0; j < n; ++j)	scanf("%d", &a[j]);
		for(j = 0; j < n; ++j)	scanf("%d", &b[j]);
		qsort(a, n, sizeof(a[0]), cmp1);
		qsort(b, n, sizeof(b[0]), cmp2);
		ans = 0;
		for(j = 0; j < n; ++j)	ans += a[j] * b[j];
		printf("case #%d:\n%d\n", i, ans);
	}
	return 0;
}