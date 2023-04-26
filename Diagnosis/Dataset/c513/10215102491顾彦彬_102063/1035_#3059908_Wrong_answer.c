#include<stdio.h>
#include<stdlib.h>

int table[1000][2];

int cmp1(const void *a,const void *b)
{
	int *x,*y;
	x=*(int(*)[0])a;
	y=*(int(*)[0])b;
	return y-x;
}

main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&table[i][0],&table[i][1]);
	}
	qsort(table,n,sizeof(table[0]),cmp1);
	long long int size_top=table[0][0]*table[0][0];
	long long int size_side=0;
	for (int i=0;i<m;i++)
	{
		size_side+=table[i][0]*2*table[i][1];
	}
	printf("%lld",size_side+size_top);
}