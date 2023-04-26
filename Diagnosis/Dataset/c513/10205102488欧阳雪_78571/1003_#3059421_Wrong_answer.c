#include<stdio.h>
#include<stdlib.h>
struct data{
	long long int n;
	int cnt;
};
int cmp(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	if(c.cnt !=d.cnt  )
	{
		return d.cnt -c.cnt ;
	}
	else{
		return c.n -d.n ;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		int j=0,t=0;
		struct data a[10001];
		for(j=0;j<N;j++)
		{
			scanf("%lld",&a[j].n);
			int d=1;
			a[j].cnt =0;
			for(t=0;t<64;t++)
			{
				if(a[j].n &d)
				{
					a[j].cnt ++;
				}
				d=d<<1;
			}
		}
		qsort(a,N,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<N;j++)
		{
			printf("%lld ",a[j].n );
	    }
	    printf("\n");
	}
}