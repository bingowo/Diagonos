#include <stdio.h>

solve(int T)
{
	unsigned long long a[31];
	a[0]=1;
	int i;
	for (i=1;i<=30;i++){
		a[i]=a[i-1]*2;
	}
	int N;
	scanf("%d",&N);
	printf("%llu\n",a[N]);
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
}