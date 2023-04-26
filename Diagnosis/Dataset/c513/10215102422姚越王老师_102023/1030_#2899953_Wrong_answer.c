#include<stdio.h>
#include<stdlib.h>
int get_high(int n)
{
	int a;
	if(n<0)a=-n;
	else a=n;
	while(a>=10)a/=10;
	return a;
}
int cmp(const void* a,const void* b)
{
	long long *p1=(long long*)a,*p2=(long long*)b;
	int n1=get_high(*p1),n2=get_high(*p2);
	if(n1!=n2)return n2-n1;
	else 
	{
		if(*p1<*p2)return -1;
		else return 1;
	}
}
int main()
{
	int T,N,i,j;scanf("%d\n",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		long long a[N];
		for(j=0;j<N;j++)
		{
			scanf("%lld",&a[j]);
		}
		qsort(a,N,sizeof(long long),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<N;j++)printf("%lld ",a[j]);
		printf("\n");
	}
	return 0;
}