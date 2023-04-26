#include <stdio.h>

long long f(int n)
{
	long long m,x,y;
	int cnt;
	x=0;y=1;cnt=1;
	while (cnt<n){
		m = y;
		y = x+y;
		x = m;
		cnt++;
	}
	if (n==0) y=0;
	return y;
}

int main()
{
	int T;int a[10];int i;
	scanf("%d",&T);
	for (i=0;i<T;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<T;i++){
		printf("case #%d:\n%lld\n",i,f(a[i]));
	}
	return 0;
} 
