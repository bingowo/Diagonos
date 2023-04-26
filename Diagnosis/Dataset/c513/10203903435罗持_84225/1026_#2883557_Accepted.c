#include <stdio.h>
#include <stdlib.h>
long long a[100010] = {0};
int mycmp(const void*aa,const void*bb)
{
	long long a = *(long long*)aa;
	long long b = *(long long*)bb;
	if(a>=b) return -1;
	else return 1;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	qsort(a+1,n,sizeof(a[0]),mycmp);
	long long res = 0;
	for(int i=1;i<=n;i=i+2) res += a[i]-a[i+1];
	printf("%lld",res);
	return 0;
}