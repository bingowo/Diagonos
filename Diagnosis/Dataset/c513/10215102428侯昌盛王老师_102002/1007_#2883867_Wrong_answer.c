#include <stdio.h>

#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	int *q,*p;
	*q=*(int*)a;
	*p=*(int*)b;
	return *p-*q;
}
int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		long long int w;
		scanf("%lld",&w);
		int j=0,ve=0,k=0,d,l=0;
		int m[100];
		while(w)
		{
			d=w%2;
			m[l++]=d;

			w/=2;
		}
		int n[100];

		for(j;j<l-1;j++)
		{
			if(m[j]!=m[j+1]) ve++;
			else{
				n[k++]=ve;
				ve=0;
			}
			
		}
		qsort(n,100,sizeof(n[0]),cmp);
		printf("case #%d:\n",i);
		printf("%d\n",n[0]);
		
	}
	return 0;
 } 