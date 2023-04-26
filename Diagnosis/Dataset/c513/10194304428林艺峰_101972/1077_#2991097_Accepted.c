#include<stdio.h>
#include<stdlib.h>
int A[510], B[510], order[1010], C[510];
int cmp1(const void *a, const void *b){
	const int *pa = a, *pb = b;
	if(order[*pa] > order[*pb]){
		return 1;
	}
	return -1;
}
int cmp2(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
int main(){
	int m, n, i, len_in = 0, len_C = 0;
	scanf("%d", &m);
	for(i = 1; i <= m; ++i){
		scanf("%d", &A[i]);
		order[A[i]] = i;
	}
	scanf("%d", &n);
	for(i = 1; i <= n; ++i){
		scanf("%d", &B[i]);
		if(order[B[i]]){
			C[len_in++] = B[i];
		}
	}
	len_C = len_in;
	for(i = 1; i <= n; ++i){
		if(!order[B[i]]){
			C[len_C++] = B[i];
		}
	}
	qsort(C, len_in, sizeof(C[0]), cmp1);
	qsort(C + len_in, len_C - len_in, sizeof(C[len_in]), cmp2);
	for(i = 0; i < len_C; ++i){
		printf("%d ", C[i]);
	}
	return 0;
}