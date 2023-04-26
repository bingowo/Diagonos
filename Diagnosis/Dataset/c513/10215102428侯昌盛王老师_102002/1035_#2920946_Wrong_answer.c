#include <stdio.h>
#include <stdlib.h>

struct s{
	int r;
	long long int h;
	long long int s;
};

int cmp(const void*a,const void*b)
{
	long long int q,p;
	q=*(int*)a;
	p=*(int*)b;
	return p-q;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	struct s a[n];
	int i=0;
	for(i;i<n;i++)
	{
		scanf("%d %lld",&a[i].r,&a[i].h);
		a[i].s=2*(a[i].r)*(a[i].r)+2*(a[i].r)*a[i].h;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	int sum=0,j=0;
	for(j;j<m;j++) sum+=a[j].s;
	printf("%d\n",sum);
	return 0;
}