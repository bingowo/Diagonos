#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
long long a[1005],b[500501],sum[500501];
int cmp(const void* a,const void* b)
{
	long long x=*(long long*)a;long long y=*(long long*)b;
	if(x<y)return -1;
	return 1;
}
int main()
{
	int n,m;a[0]=0;sum[0]=0;
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		long long x;int l,r;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			a[i]=a[i-1]+x;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		b[++cnt]=a[j]-a[i-1];
		qsort(b+1,cnt,sizeof(long long),cmp);
		for(int i=1;i<=cnt;i++)sum[i]=sum[i-1]+b[i];
		printf("case #%d:\n",ct++);
		while(m--)
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",sum[r]-sum[l-1]);
		}
	}
	return 0;
}