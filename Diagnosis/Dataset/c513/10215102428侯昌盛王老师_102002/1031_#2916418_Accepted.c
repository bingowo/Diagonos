#include <stdio.h>
#include <stdlib.h>
int cmpa(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int cmpb(const void*a,const void*b)
{
	return *(int*)b-*(int*)a;
}


int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int a[n],b[n];
		int j;
		for(j=0;j<n;j++) scanf("%d",&a[j]);
		for(j=0;j<n;j++) scanf("%d",&b[j]);
		
		qsort(a,n,sizeof(a[0]),cmpa);
		qsort(b,n,sizeof(b[0]),cmpb);
		int sum=0,k=0;
		for(k;k<n;k++)
		{
			sum=sum+(a[k]*b[k]);
		}
		printf("case #%d:\n",i);
		printf("%d\n",sum);
	
	}
	return 0;
}