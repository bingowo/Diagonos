#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int T,cas,n,m,tmp,L,U,i,j,k;scanf("%d",&T);
	for(cas=0;cas<T;++cas)
	{
		scanf("%d %d",&n,&m);
		int a[n],len=n*(n+1)/2,b[len+1],cnt=1;b[0]=0;
		for(i=0;i<n;++i)scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmp);
		for(i=1;i<=n;++i)
		{
			
			for(j=0;j<n-i+1;++j)
			{
				tmp=0;
				for(k=0;k<i;++k)tmp+=a[j+k];
				b[cnt++]=tmp;
			}
		}
		qsort(b,cnt,sizeof(int),cmp);
		printf("case #%d:\n",cas);
		for(i=0;i<m;++i)
		{
			scanf("%d %d",&L,&U);
			tmp=0;
			for(j=L;j<=U;j++)tmp+=b[j];
			printf("%d\n",tmp);
		}
	}
	return 0;
}