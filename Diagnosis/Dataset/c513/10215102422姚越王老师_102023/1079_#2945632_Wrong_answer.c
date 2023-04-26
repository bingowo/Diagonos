#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long ull;
int cmp(const void* a,const void* b)
{
	if(*(ull*)a<*(ull*)b)return 0;
	else return 1;
}
int main()
{
	int T,cas,n,m,L,U,i,j,k,cnt,len;scanf("%d",&T);
	for(cas=0;cas<T;++cas)
	{
		scanf("%d %d",&n,&m);
		len=n*(n+1)/2;
		ull a[n],b[len+1],tmp;b[0]=0;cnt=1;
		for(i=0;i<n;++i)scanf("%llu",&a[i]);
		qsort(a,n,sizeof(ull),cmp);
		for(i=1;i<=n;++i)
		{
			
			for(j=0;j<n-i+1;++j)
			{
				tmp=0;
				for(k=0;k<i;++k)tmp+=a[j+k];
				b[cnt++]=tmp;
			}
		}
		qsort(b,cnt,sizeof(ull),cmp);
		printf("case #%d:\n",cas);
		for(i=0;i<m;++i)
		{
			scanf("%d %d",&L,&U);
			tmp=0;
			for(j=L;j<=U;j++)tmp+=b[j];
			printf("%llu\n",tmp);
		}
	}
	return 0;
}