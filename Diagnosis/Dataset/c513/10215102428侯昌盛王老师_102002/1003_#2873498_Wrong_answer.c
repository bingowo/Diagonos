#include <stdio.h>
#include <stdlib.h>
	
	
	
int cmp(const void*a,const void*b)
{
	struct hsort
	{
		long long int num;
		int a;	
	};
	struct hsort m,n;
	m=*(struct hsort*)a;
	n=*(struct hsort*)b;
	if(m.a!=n.a) return n.a-m.a;
	else
	{
		if(m.num<n.num) return -1;
		else return 1;
	}
	
}

int main()
{
	struct hsort
	{
		long long int num;
		int a;	
	};
	int t,n;
	scanf("%d",&t);
	int i=0;
	for(i;i<t;i++)
	{
		scanf("%d",&n);
		int y=0,r=1;
		int j=0;
		struct hsort p[n];
		for(y;y<n;y++)
		{
			scanf("%lld",&p[y].num);
			int a=0;
			for(j;j<64;j++)
			{
				if(p[i].num&r) p[y].a++;
				r<<1;
			}
		}
		qsort(p,n,sizeof(p[0]),cmp);
		int k=0;
		printf("case #%d\n",i);
		for(k;k<n;k++) printf("%lld ",p[k].num);
		printf("\n");
		
	}
	return 0;
	
	
	
}