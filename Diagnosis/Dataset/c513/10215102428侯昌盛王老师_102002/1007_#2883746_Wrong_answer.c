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
		int w;
		scanf("%d",&w);
		int j=0,ve=0,k=0,d,len=0;
		int m[100];
		while(w)
		{
			d=w%2;
			m[k++]=d;
			len++;
			w/=2;
		}
		int n[100];

		for(j;j<len-1;j++)
		{
			if(m[j]!=m[j+1]) ve++;
			else{
				n[k++]=ve;
				ve=0;
			}
			
		}
		qsort(n,100,sizeof(n[0]),cmp);
		printf("case #%d:\n",i);
		printf("%d\n",n[k-1]);
		
	}
	return 0;
 } 