#include <stdio.h>
#include <stdlib.h>

int num(long long N){
	int ret = 0;
	unsigned long long n = N;
	if (n < 0)
		n = 1 << 64 + n;

	while (n){
		ret += n & 1;
		n = n >> 1;
	}
	return ret;
}

int cmp(const void *a, const void *b){
	long long *p = (long long *)a;
	long long *q = (long long *)b;
	int m = num(*p);
	int n = num(*q);
	if (m != n)
		return n - m;
	return *p - *q;
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