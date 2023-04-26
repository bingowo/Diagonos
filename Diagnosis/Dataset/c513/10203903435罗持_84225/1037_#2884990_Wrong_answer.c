#include <stdio.h>
#include <stdlib.h>
long long a[1000010] = {0};
long long pre[1000010] = {0};
int mycmp(const void*aa,const void*bb)
{
	long long x = *(long long*)aa;
	long long y = *(long long*)bb;
	if(x>y) return 1;
	else return -1;
}
int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	qsort(a+1,n,sizeof(a[0]),mycmp);
	for(int i=1;i<=n;i++) pre[i] = pre[i-1]+a[i];
	long long res = pre[n];
	for(int i=m;i<=n;i++)
	{
		long long ans = a[i]*(m-1)-(pre[i-1]-pre[i-m]);
		if(ans < res) res = ans;
	}
	printf("%lld",res);
	return 0;
}
