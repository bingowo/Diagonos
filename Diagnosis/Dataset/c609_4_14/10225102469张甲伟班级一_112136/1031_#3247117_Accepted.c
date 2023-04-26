#include<stdio.h>
#include<stdlib.h>
int T,n,m,L,U,a[10000],suma[10000];
long long b[5500000],sumb[5500000];
int cmp(const void *e1,const void *e2)
{
	return  *(int*)e1-*(int*)e2;
}
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int cnt=1;
		scanf("%d%d",&n,&m);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			suma[j]=suma[j-1]+a[j];
		}
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<j;k++)
			{
				b[cnt++]=suma[j]-suma[k];
				sum++;
			}
		}
		qsort(b,n*(n+1)/2+1,sizeof(b[0]),cmp);
//		for(int j=1;j<=n*(n+1)/2+1;j++)	printf("%d ",b[j]);
//		printf("\n");
		for(int j=1;j<=n*(n+1)/2+1;j++)
			sumb[j]=sumb[j-1]+b[j];
		printf("case #%d:\n",i);
		while(m--)
		{
			scanf("%d%d",&L,&U);
			printf("%lld\n",sumb[U]-sumb[L-1]);
		}
	}
	return 0;
}