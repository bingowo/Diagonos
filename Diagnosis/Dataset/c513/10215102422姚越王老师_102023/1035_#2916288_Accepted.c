#include<stdio.h>
#include<stdlib.h>
typedef struct{long long R,H,sc,sd;} col;
long long Max(long long a,long long b)
{
	if(a>b)return a;
	else return b;
}
int cmp(const void* a,const void* b)
{
	col ax=*(col*)a,bx=*(col*)b;
	if(ax.sc>bx.sc)return -1;
	else return 1;
}
int main()
{
	int n,m,i,j,k;scanf("%d%d",&n,&m);
	col a[n];
	long long ans=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].R,&a[i].H);
		a[i].sc=2*a[i].R*a[i].H;a[i].sd=a[i].R*a[i].R;
	}
	for(i=0;i<n;i++)
	{
		col ax[n];k=0;
		long long tmp=0;
		for(j=0;j<n;j++) if(j!=i&&a[j].sd<=a[i].sd)ax[k++]=a[j]; 
		qsort(ax,k,sizeof(ax[0]),cmp);
		for(j=0;j<k&&j<m-1;j++)tmp+=ax[j].sc;
		tmp+=a[i].sd;tmp+=a[i].sc;
		ans=Max(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}