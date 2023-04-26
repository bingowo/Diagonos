#include<stdio.h>
#include<stdlib.h>

typedef long long int lli;
/*排序不等式*/

int ascand(const void *a,const void *b)
{
	const lli *pa = (const lli *)a;
	const lli *pb = (const lli *)b;
	return pa > pb ? 1:-1;
 } 
 
 int descand(const void *a,const void *b)
{
	const lli *pa = (const lli *)a;
	const lli *pb = (const lli *)b;
	return pa > pb ? -1:1;
 } 
 
 
 int main()
 {
 	int t;
 	scanf("%d",&t); 
 	int i;
 	for(i=0;i<t;i++)
 	{
 		int n;
 		lli res=0;
 		scanf("%d",&n);
 		lli a[n],b[n];
 		int j;
 		for(j=0;j<n;j++)
 		{
 			scanf("%lld",&a[j]);
		 }
		for(j=0;j<n;j++)
		{
			scanf("%lld",&b[j]);
		}
		qsort(a,n,sizeof(lli),ascand);
		qsort(b,n,sizeof(lli),descand);
		for(j=0;j<n;j++)
		{
			res+=(a[j]*b[j]);
		}
		printf("case #%d:\n",i);
		printf("%lld\n",res);
	 }
	 return 0;
 }