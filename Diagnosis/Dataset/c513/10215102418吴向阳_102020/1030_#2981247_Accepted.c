#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void*b)
{
	long long *p = (long long *)a,*q = (long long *)b;
	long long x = *p,y = *q;
	if(x < 0) x = -x;
	if(y < 0) y = -y;
	while(x >= 10) x /= 10;
	while(y >= 10) y /= 10;
	if(x != y) return y-x;
	else
	{
		if(*p-*q > 0) return 1;
		else return -1;
	}
}

int main()
{
	int T,t;
	scanf("%d",&T);
	t=T;
	while(T)
	{
		int N;
		scanf("%d",&N);
		long long a[N];
		for (int i = 0; i < N; i++) scanf("%lld",&a[i]);
		qsort(a,N,sizeof(a[0]),cmp);
		printf("case #%d:\n",t-T);
		for(int i = 0;i < N;i++) printf("%lld ",a[i]);
		printf("\n");
		T--;
	}
} 