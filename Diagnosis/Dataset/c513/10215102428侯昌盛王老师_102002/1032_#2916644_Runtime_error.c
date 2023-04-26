#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
	int *q,*p;
	q=(int*)a;
	p=(int*)b;
	while(*q==*p)
	{
		q++;p++;
		
	}
	return *p-*q;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int a[n][50];
		int count=0;
		for(count;count<n;count++)
		{
			int j=0;
			do{
				scanf("%d",&a[count][j]);
				j++;
			}while(a[count][j-1]!=-1);
			//printf("%d\n",a[count][1]);
		
		}
		//printf("%d",a[1][1]);
		qsort(a,n,sizeof(a[0]),cmp);
		//printf("%d",a[1][1]);
		int k=0,d=0;
		while(k<n)
		{
			while(a[k][d]!=-1)
			{
				printf("%d ",a[k][d]);
				d++;
			}
			printf("\n");
			d=0;
			k++;
		}
	}
	return 0;
}
