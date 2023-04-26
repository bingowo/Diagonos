#include <stdio.h>
#include <stdlib.h>

long long int Num(long long int a)
{
	int res=0;
	int i;
	long long int num=1;
	for(i=0;i<64;i++)
	{
		if((a&num)==num)res++;
		num=num<<1;
	}
	return res;
}
int cmp(const void *a1,const void *b1)
{
	long long int *a=(long long int *)a1; 
	long long int *b=(long long int *)b1;
	if(num(*a)!=num(*b))return (num(*a)<num(*b))?1:-1;
	else return (*a>*b)?1:-1;
}
void Sort(long long int *p,int n)
{
	qsort(p,n,sizeof(long long int),cmp);
}
int main()
{
	int t,i;
	long long int a[20000];
	int j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%lld",&n);
		if(n==1)
		{
			scanf("%lld",&a[0]);
			printf("case #%d:\n",i);
			printf("%lld\n",a[0]);
		}
		else
		{
			for(j=0;j<n;j++)
			{
				scanf("%lld ",&a[j]);
			}//完成每个问题中N个数的读入
			Sort(a,n);
			printf("case #%d:\n",i);
			for(j=0;j<n;j++)
			{
				printf("%lld ",a[j]);
			}
			printf("\n");
		}
			
		
	}
	return 0;
}