#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned long long ra;
	unsigned long long be;
	unsigned long long un;
}COL;
int cmp1(const void* a,const void* b)
{
	COL x,y;
	x=*(COL*)a;
	y=*(COL*)b;
	if(x.be>y.be){
		return -1;
	}
	return 1;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	COL col[1000];
	int i;
	int r,h,rmax=0;
	for (i=0;i<n;i++){
		scanf("%d %d",&r,&h);
		col[i].ra=r;
		col[i].be=2*r*h;
		col[i].un=r*r;
	}
	qsort(col,n,sizeof(col[0]),cmp1);
	unsigned long long max=0;
	for (i=0;i<m;i++){
		max+=col[i].be;
		if(rmax<col[i].ra){
			rmax=col[i].ra;
		}
	}
	max+=rmax*rmax;
	printf("%llu\n",max);
	return 0;
}