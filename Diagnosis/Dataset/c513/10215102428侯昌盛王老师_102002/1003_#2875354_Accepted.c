#include <stdio.h>
#include <stdlib.h>
struct hsort
	{
		long long int num;
		int a;	
	};
int cmp(const void*w,const void*b)
{
	
	struct hsort m,n;
	m=*((struct hsort*)w);
	n=*((struct hsort*)b);
	if(m.a!=n.a) return n.a-m.a;
	else
	{
		if(m.num>n.num) return 1;
		else return -1;
	}
	
}

int main()
{

	int t,n;
	scanf("%d",&t);
	int i=0;
	for(i;i<t;i++)
	{
		scanf("%d",&n);
		int y=0;
		int j=0;
		struct hsort p[n];
		for(y;y<n;y++)
		{
			scanf("%lld",&p[y].num);
			p[y].a=0;
			long long int r=1;
			for(j;j<64;j++)
			{
				if(p[y].num&r) p[y].a++;
				r=r<<1;
			}
		
			j=0;
		}
		qsort(p,n,sizeof(p[0]),cmp);
		int k=0;
		printf("case #%d:\n",i);
		for(k;k<n;k++) printf("%lld ",p[k].num);
		printf("\n");
		
	}
	return 0;
	
	
	
}