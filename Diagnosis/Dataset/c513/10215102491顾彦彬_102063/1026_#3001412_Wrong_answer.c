#include<stdio.h>
#include<stdlib.h>

int cmp1(const void *a,const void *b)
{
	return *(long long int *)a - *(long long int *)b;
}

int main()
{
	long long int n,table[100000],i=0,res=0;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld",&table[i++]);
	}
	qsort(table,i,sizeof(table[0]),cmp1);
	for (int j=0;j<n/2;j++)
	{
		res+=table[2*j+1]-table[2*j];
	}
	printf("%lld",res);
}