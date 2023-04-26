#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int a[1010],b[1010];
int mycmp1(const void*aa,const void*bb)
{
	int a = *(int*)aa;
	int b = *(int*)bb;
	if(a>b) return 1;
	else return -1;
}
int mycmp2(const void*aa,const void*bb)
{
	int a = *(int*)aa;
	int b = *(int*)bb;
	if(a<b) return 1;
	else return -1;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		qsort(a+1,n,sizeof(a[0]),mycmp1);
		qsort(b+1,n,sizeof(b[0]),mycmp2);
		long long res = 0;
		for(int i=1;i<=n;i++) res += a[i]*b[i];
		printf("case #%d:\n",kase);
		printf("%lld\n",res);
	}
	return 0;
}