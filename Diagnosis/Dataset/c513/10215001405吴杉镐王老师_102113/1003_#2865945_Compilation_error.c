#include <stdio.h>
#include <stdlib.h>

struct data
{
	long long int a;
	int number;
}

int cmp(const void *a,const void *b)
{
	struct data d1,d2;
	d1=*((struct data *)a);
	d2=*((struct data *)b);
	if(d2.number != d1.number)
	return d2.number-d1.number;
	else
	{
		if(d1.a>d2.a) return 1;
		else return -1;
	}
}

int main(int argc, char** argv) 
{
	int m;
	scanf("%d",&m);
	int j=0;
	while(j<m)
	{
		printf("case #%d:\n",j);
		j++;
		int n;
		scanf("%d",&n);
		struct data p[10000];
		int i=0;
		for(;i<n;i++)
		{
			scanf("%lld",&p[i].a);
			int d=1;
			p[i].number=0;
			int t=0;
			for(;t<64;t++)
			{
				if(p[i].a&d) p[i].number++;
				d=d<<1;
			}
		}
		qsort(p,n,sizeof(p[0]),cmp);
		for (i=0;i<n-1;i++)
		{
			printf("%lld",p[i].a);
		}
		printf("%lld\n",p[i].a);
	 } 
	return 0;
}