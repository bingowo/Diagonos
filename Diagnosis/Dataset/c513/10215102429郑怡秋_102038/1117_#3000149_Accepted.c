#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	long long x;
	long long y;
	long long res;
} HA;

int cmp(const void *p1,const void *p2)
{
	HA *p3=(HA*)p1;
	HA *p4=(HA*)p2;
	if(p3->res>p4->res) return 1;
	else if(p3->res<p4->res) return -1;
	else{
		if(p3->x>p4->x) return 1;
		else if(p3->x<p4->x) return -1;
		else {
			if(p3->y>p4->y) return 1;
			else return -1;
		}
	}
}

int main()
{
	long long c,d;
	scanf("%lld%lld",&c,&d);
	int n;
	scanf("%d",&n);
	HA *p=(HA*)malloc(n*sizeof(HA));
	int i;
	
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&p[i].x,&p[i].y);
		long long a=llabs(p[i].x-c),b=llabs(p[i].y-d);
		p[i].res=(a<b)?b:a;
	}
	qsort(p,n,sizeof(HA),cmp);
	printf("%lld\n%lld %lld",p[0].res,p[0].x,p[0].y);
	free(p);
	return 0;
}