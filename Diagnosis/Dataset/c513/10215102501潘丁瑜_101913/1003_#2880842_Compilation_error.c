#include <stdio.h>
#include<stdlib.h>
struct data
	{
		long long int a;
		int number;
	};
int cmp(const void*a,const void*b);
int main()
{
	int T,i,N,j,t;
	scanf("%d",&T);
	long long int d;
	struct data p[10000];
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		for(j=0;j<N;j++)
		{
			scanf("%lld",&p[j].a);
			d=1;
			p[j].number = 0;
			for(t=0;t<64;t++)
			{
				if(p[j].a&d ) p[j].number++;
				d=d<<1;
			}
		}
		
		qsort(p,N,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<N-1;j++)
			printf("%lld ",p[j].a);
		printf("%lld\n",p[j].a);
	}

	return 0;
}

int cmp(const void*a,const void*b)
{
	struct data d1,d2;
	d1= *((struct data *)a);
	d2= *((struct data *)b);
	if(d2.number != d1.number)
		return d2.number-d1.number;
	else
	{
		if(d1.a>d2.a) return 1;
		else return -1;
	}
	
}



}

