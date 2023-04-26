#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
long long int p=*(long long int*)a;
long long int q=*(long long int*)b;
	int i,j,k;
	j=k=0;
	for(i=31;i>=0;i++)
	{
		if(p>>i&1==1)j++;
		if(q>>i&1==1)k++;
	}
	if(j!=k)return k-j;
	else return p>q?1:-1;	
} 
int main()
{
	int t,i,n,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long long int a[10000];
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%lld",&a[j]);
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)
			printf("%lld ",a[j]);
		printf("\n");
	}
	return 0;
}