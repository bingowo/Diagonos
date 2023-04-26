#include<stdio.h>
#include<string.h>
#include <stdlib.h>
long long A[10002];
int cmp(const void *a, const void *b){
    int i, num1 = 0, num2 = 0; long long *pa = (long long *)a, *pb = (long long *)b;
    long long aa = *pa, bb = *pb;
    while(aa){
		num1++;
        aa &= (aa -1) ; // 清除最低位的1
    }
	while(bb){
		num2++;
        bb &= (bb -1) ; // 清除最低位的1
    }
    if(num1 > num2) return -1;
    if(num1 < num2) return 1;
    if(num1 == num2) return *pa > *pb ? 1 : -1;
}
void Sort(long long *ps, long long n)
{
    qsort(ps, n, sizeof(long long), cmp);
}
int main()
{
	long long t, i, j, k, n, *p = A;
	scanf("%lld", &t);
	for(i = 0; i < t; i++){
		scanf("%lld", &n);
		for(j = 0; j < n; j++){
			scanf("%lld", &A[j]);
		}
		printf("case #%lld:\n", i);
		Sort(p, n);
		for(k = 0; k < n; k++){
			printf("%lld ", A[k]);
		}
		printf("\n");
	}
	return 0;
}