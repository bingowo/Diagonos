#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	int *A=(int *)a;
	int *B=(int *)b;
	return *A-*B;
}
int main()
{
	int t,n,m,a[1001],b[500501],g,l,u,ans=0;
	int *p=b;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int k=0,o=0;k<n;k++)
		{
			b[o]=a[k];
			for(g=k+1;g<n;g++)
			{
				b[o+g-k]=b[o+g-k-1]+a[g];
			}
			o=o+n-k;
		}
		qsort(p,n*(n+1)/2,sizeof(b[0]),cmp);
		for(int y=0;y<n*(n+1)/2;y++) printf("%d ",b[y]);
		printf("case #%d:\n",i);
		for(int x=0;x<m;x++)
		{
			scanf("%d%d",&l,&u);
			for(int e=l-1;e<u;e++)
			{
				ans=ans+b[e];
			}	
			printf("%d\n",ans);
			ans=0;	
		}
		
	}
	return 0;
}