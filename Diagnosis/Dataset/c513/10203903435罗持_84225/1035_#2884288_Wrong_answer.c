#include <stdio.h>
#include <stdlib.h>
struct node
{
	long long r,h;
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
	for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].r,&a[i].h);
	qsort(a+1,n,sizeof(a[0]),mycmp);
	long long res = 0;
	long long mmax = 0;
	for(int i=1;i<=n;i++)
	{
		long long ans = a[i].r * a[i].r;
		int have = 1;
		for(int j=1;have<=m;j++)
		{
			if(i==j||a[j].r > a[i].r) continue;
			ans += 2*a[j].r*a[j].h;
			have++;
		}
		if(ans > res) res = ans;
	}
	printf("%lld",res);
	return 0;
}