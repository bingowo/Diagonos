#include <stdio.h>

int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		long long int w;
		scanf("%lld",&w);
		int j=0,ve=1,k=0,d,l=0;
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
			if(m[j]!=m[j+1])
			{
				ve++;
				if(j==l-2) n[k++]=ve;
			}
			else{
				n[k++]=ve;
				ve=1;
			}
			
			//printf("%d\n",n[k-1]);
			
		}
		int max=n[0];
		int e=1;
		for(e;e<k;e++)
		{
			if(n[e]>max) max=n[e];
		}
		printf("case #%d:\n",i);
		printf("%d\n",max);
		
	}
	return 0;
 } 