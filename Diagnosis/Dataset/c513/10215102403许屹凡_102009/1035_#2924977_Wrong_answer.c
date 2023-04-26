#include <stdio.h>
long long Max(long long int a, long long int b)
{
	if(a>b) return a;
	else return b;
}
int cmp(int a, int b)
{
	return a>b;
}
struct cylinder
{
	int radius,height;
	long long product;
} ;
int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	struct cylinder a[1000];
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d%d",&a[i].radius,&a[i].height);
		a[i].product = (long long)a[i].radius*a[i].height;
	}
	long long ans=0;
	for(i=0;i<n;i++)
	{
		struct cylinder ax[1000];
		int k=0,j=0;
		for(j=0;j<n;j++)
			if (j!=i && a[j].radius <= a[i].radius) ax[k++] = a[j];
		qsort(ax,k,sizeof(ax[0]),cmp);
		long long area=0;
		if (k!=0 && k>=m-1)
		{
			int cnt=0;
			for(cnt=0; cnt<m-1; cnt++) area += ax[cnt].product;
		 } 
		 ans = Max(ans,area*2+(long long)a[i].radius*a[i].radius+2*a[i].product);
	}
	printf("%lld",ans);
	return 0;
 } 