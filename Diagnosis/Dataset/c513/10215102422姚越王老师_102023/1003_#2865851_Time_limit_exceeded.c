#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef long long ll;
typedef struct{ll a;int n;} num;
int cmp(const void* a,const void* b)
{
	num *ax=(num*)a,*bx=(num*)b;
	if(ax->n!=bx->n)return bx->n-ax->n;
	else
	{
		if(ax->a>bx->a)return 1;
		else return -1;
	}
}
int count(ll a)
{
	int cnt=0,p=1,number=0;
	while(cnt<64)
	{
		if(a&p)number++;
		p<<=1;
	}
	return number;
}
int main()
{
	int total,n;
	scanf("%d",&total);
	int cnt=0;
	int i=0;
	while(cnt<total)
	{
		scanf("%d",&n);
		num* array=(num*)malloc(sizeof(num)*n);
		for(i;i<n;i++)
		{
			scanf("%lld",&array[i].a);
			array[i].n=count(array[i].a);
		}
		qsort(array,n,sizeof(array[0]),cmp);
		printf("case #%c:\n",cnt+48);
		i=0;
		for(i;i<n-1;i++)printf("%lld ",array[i].a);
		printf("%lld\n",array[i].a);
		i=0;
		free(array);
	}
	return 0;
}