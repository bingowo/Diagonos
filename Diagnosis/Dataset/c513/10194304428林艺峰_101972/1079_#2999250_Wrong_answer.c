#include<stdio.h>
#include<stdlib.h>
int a[1010], num[510000], ans[21];
int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
int main(){
	int t, n, m, i, j, k, cnt, sum, l, u;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d%d", &n, &m);
		cnt = 0;
		for(j = 0; j < n; ++j){
			scanf("%d", &a[j]);
		}
		for(j = 0; j < n; ++j){
			sum = 0;
			for(k = j; k < n; ++k){
				sum += a[k];
				num[cnt++] = sum;
			}
		}
		qsort(num, cnt, sizeof(num[0]), cmp);
		cnt = 0;
		for(j = 0; j < m; ++j){
			scanf("%d%d", &l, &u);
			sum = 0;
			for(k = l - 1; k <= u - 1; ++k){
				sum += num[k];
			}
			ans[cnt++] = sum;
		}
		printf("case #%d:\n", i);
		for(j = 0; j < cnt; ++j){
			printf("%d\n", ans[j]);
		}
		/*for(j = 0; j < cnt; ++j){
			printf("%d ", num[j]);
		}*/
		
	}
	return 0;
}