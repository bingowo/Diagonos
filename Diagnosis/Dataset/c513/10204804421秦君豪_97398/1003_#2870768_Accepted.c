#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a1,const void* a2)
{

	unsigned long long int a = *(long long int*)a1;
	unsigned long long int b = *(long long int*)a2;
	int n1=0,n2=0;
	while(a!=0)
	{
		if(a&1==1) 
		{
			n1++;
		}
		a=(a>>1);
	}
	while(b!=0)
	{
		if(b&1==1)
		{
			n2++;
		}
		b=(b>>1);
	}
	if (n1==n2) return *(long long int*)a1>*(long long int*)a2?1:-1;
	else return n1>n2?-1:1;
}
int main()
{
	int T,N,i,j,k;
	long long int* a = (long long int*)malloc(10000*sizeof(long long int));
	scanf("%d",&T);
	for (i=0;i<T;i++)
	{
		scanf("%d",&N);
		for (j=0;j<N;j++)
		{
			scanf("%lld",&a[j]);			
		}
//		printf("pass");
		qsort(a,N,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for (k=0;k<N;k++)
		{
			printf("%lld ",a[k]);
		}
		putchar('\n');
	}
	free(a);
	return 0;//
}