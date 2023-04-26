#include<stdio.h>

long long int lliabs(long long int x)
{
	return x < 0 ? -x : x;
}

int cmp(const void *a,const void *b)
{
	long long int *aa = (long long int *)a;
	long long int *bb = (long long int *)b;
	return aa>bb? 1:-1;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long int array[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&array[i]);
	}
	qsort(array,n,sizeof(long long int),cmp);
	long long int resabs;
	for (i=0;i<n;i+=2)
	{
		resabs+=lliabs(array[i]-array[i+1]);
	}
	printf("%lld",resabs);
}