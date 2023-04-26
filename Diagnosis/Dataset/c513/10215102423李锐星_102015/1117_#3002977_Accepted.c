#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	long long x;
	long long y;
	unsigned long long d;
}P;

P a[1000000];

int cmp(const void* a,const void* b)
{
	P m,n;
	m=*(P*)a;
	n=*(P*)b;
	if(m.d<n.d) return -1;
	if(m.d>n.d) return 1;
	if(m.x<n.x) return -1;
	if(m.x>n.x) return 1;
	if(m.y<n.y) return -1;
	return 1;
}

int main()
{
	long long  x0,y0;
	scanf("%lld %lld",&x0,&y0);
	int n;
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		scanf("%lld %lld",&a[i].x,&a[i].y);
		unsigned long long d1,d2;
		d1=llabs(a[i].x-x0);
		d2=llabs(a[i].y-y0);
		if(d1>=d2){
			a[i].d=d1;
		}
		else{
			a[i].d=d2;
		}
	}
	qsort(a,n,sizeof(P),cmp);
	printf("%llu\n",a[0].d);
	printf("%lld %lld\n",a[0].x,a[0].y);
	return 0;
}