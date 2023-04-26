#include <stdio.h>
#include <stdlib.h>

int num(long long N){
	int cnt = 0;
	int i;
	long long m = 1;
	for (i = 0; i < 64; i++, m = m << 1){
		if (N & m)
			cnt++;
	}
	return cnt;
}

int cmp(const void *a, const void *b){
	long long *p = (long long *)a;
	long long *q = (long long *)b;
	int m = num(*p);
	int n = num(*q);
	if (m != n)
		return n - m;

	if (*p > *q)
		return 1;
	return -1;
}

int main(){
	int ncase, T;
	scanf("%d",&T);
	for (ncase = 0; ncase < T; ncase++){
		int N;
		scanf("%d", &N);
		long long a[N];
		for (int i = 0; i < N; i++)
			scanf("%lld",&a[i]);
		
		qsort(a,N,sizeof(a[0]), cmp);
		
		//输出
		printf("case #%d:\n",ncase);
		
		for (int i = 0; i < N; i++){
			printf("%lld",a[i]);
			if (i == N - 1)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}
