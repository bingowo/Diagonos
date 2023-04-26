#include <stdio.h>
#include <stdlib.h>
struct node
{
	int r,h;
}a[1010];
int mycmp(const void*aa,const void*bb)
{
	struct node a = *(struct node*)aa;
	struct node b = *(struct node*)bb;
	if(a.r*a.h < b.r*b.h) return 1;
	else return -1;
}
int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i].r,&a[i].h);
	qsort(a+1,n,sizeof(a[0]),mycmp);
	long long res = 0;
	int mmax = 0;
	for(int i=1;i<=m;i++)
	{
		if(a[i].r > mmax) mmax = a[i].r;
		res += 2*a[i].r*a[i].h;
	}
	res += mmax*mmax;
	printf("%lld",res);
	return 0;
}