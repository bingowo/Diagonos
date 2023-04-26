#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	return x-y;
}

int cmp2(const void *a,const void *b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	return y-x;
}

main()
{
	int T,N,M,k=0;
	scanf("%d",&T);
	while(T--)
	{
		int t1[1000],t2[1000],i=0;
		scanf("%d",&N);
		M=N;
		while(N--)
		{
			scanf("%d",&t1[i++]);
		}
		i=0;
		while(M--)
		{
			scanf("%d",&t2[i++]);
		}
		qsort(t1,i,sizeof(t1[0]),cmp1);
		qsort(t2,i,sizeof(t2[0]),cmp2);
		long long int res=0;
		for (int j=0;j<i;j++)
		{
			res+=t1[j]*t2[j];
			//printf("%d",t1[j]);
		}
		printf("case #%d:\n%lld\n",k++,res);
	}
}