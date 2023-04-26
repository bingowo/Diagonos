#include <stdio.h>
#include <stdlib.h>

struct s{
	int r;
	long long int h;
	long long int s;
};

int cmp(const void*a,const void*b)
{
	int r1,r2;
	r1=*(int*)a;
	r2=*(int*)b;
	return r2-r1;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	struct s a[n];
	int i=0;
	for(i;i<n;i++) scanf("%d %lld",&a[i].r,&a[i].h);
	qsort(a,n,sizeof(a[0]),cmp);
	a[0].s=a[0].r*a[0].r+2*a[0].r*a[0].h;
	for(i=1;i<n;i++) a[i].s=2*a[i].r*a[i].h;
	int sum=0;
	for(i=0;i<m;i++) sum+=a[i].s;
	printf("%d\n",sum);
	return 0;
	

}