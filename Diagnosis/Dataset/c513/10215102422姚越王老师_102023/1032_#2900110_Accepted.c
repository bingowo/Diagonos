#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
	long long *p1=*(long long**)a,*p2=*(long long**)b;
	int i;
	for(i=0;i<50;i++)
	{
		if(p1[i]>p2[i])return -1;
		else if(p1[i]<p2[i])return 1;
	}
}
int main()
{
	int T,N,i,j,k;scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		long long **a,*b;
		a=(long long**)malloc(N*sizeof(long long*));
		for(j=0;j<N;j++)
		{
			b=(long long*)malloc(51*sizeof(long long));
			for(k=0;k<51;k++)
			{ 
				scanf("%lld",&b[k]);
				if(b[k]==-1)break;
			}
			for(++k;k<51;k++)b[k]=-1;
			a[j]=b;
		}
		qsort(a,N,sizeof(long long*),cmp);
		for(j=0;j<N;j++)
		{
			for(k=0;k<51;k++)
			{
				if(a[j][k]!=-1)printf("%lld ",a[j][k]);
				else break;
			}
			printf("\n");
		}
		for(j=0;j<N;j++)
		{
			b=a[j];
			free(b);
		}
		free(a);
	}
	return 0;
}