#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a, const void*b);
int main(){
	int T;
	int N;
	scanf("%d", &T);
	for(int t = 0; t<T; t++){
		scanf("%d", &N);
		long long* array = (long long*)malloc(N*sizeof(long long));
		for(int i = 0; i<N; i++){
			scanf("%lld", &array[i]);
		}
		qsort(array, N, sizeof(long long), cmp);
		printf("case #%d:\n", t);
		for(int i = 0; i<N-1; i++){
			printf("%lld ", array[i]);
		}
		printf("%lld\n", array[N-1]);
	}
	return 0;
}
int cmp(const void*a, const void*b){
	long long x = *((long long*)a);
	long long y = *((long long*)b);
	int cnt_x = 0;
	int cnt_y = 0;
	for(int i = 0; i<64; i++){
		cnt_x += (((unsigned long long)x >> i) & 1 )?1 : 0;
		cnt_y += (((unsigned long long)y >> i) & 1 )?1 : 0;
	}
	if(cnt_x == cnt_y){
		if(x<y){
			return -1;
		}
		if(x>y){
			return 1;
		}
		if{
			return 0;
		}
	}
	else{
		return cnt_y - cnt_x;
	}
}