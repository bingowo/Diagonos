#include <stdio.h>

#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	int *q,*p;
	*q=*(int*)a;
	*p=*(int*)b;
	return *q-*p;
}
int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		long long int w;
		scanf("%lld",&w);
		int j=0,ve=0,k=0,d,l=0,m[100];
		d=w%2;
		while(w)
		{
			if(w!=d)
			{
				ve++;
				w=w%2;
				d=d%2;
			}
			else{
				m[k++]=ve;
				ve=0;
				w=w%2;
				d=d%2;
			}
		}
	
		qsort(m,100,sizeof(m[0]),cmp);
		printf("case #%d:\n",i);
		printf("%d\n",m[k-1]);
		
	}
	return 0;
 } 