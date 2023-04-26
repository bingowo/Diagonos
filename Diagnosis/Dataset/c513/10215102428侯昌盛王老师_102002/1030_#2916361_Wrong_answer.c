#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct h{
	long long int x;
	int b;
};

int cmp(const void*a,const void*b)
{
	struct h *p,*q;
	p=(struct h*)a;
	q=(struct h*)b;
	if((p->b) !=(q->b)) return (q->b)-(p->b);
	else
	{
		if((q->x)>(p->x)) return -1;
		else if((q->x)<(p->x)) return 1;
		else return 0;
	}
	
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		struct h a[n];
		int j=0;
		for(j;j<n;j++) {
			scanf("%lld",&a[j].x);
			long long int y=abs(a[j].x);
			if(y==0) a[j].b=0;
			else{
				while(y)
				{
					if(y<10) a[j].b=y;
					y/=10;
				
				}
			}
		//	printf("%d\n",a[j].b);
		
		}
		qsort(a,n,sizeof(a[0]),cmp);
		int k=0;
		printf("case #%d:\n",i);
		for(k;k<n;k++)
		{
			printf("%lld ",a[k].x); 
		}
		printf("\n");
		
		
	 } 
	 return 0;
}