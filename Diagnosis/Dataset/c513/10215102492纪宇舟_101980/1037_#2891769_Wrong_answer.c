#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void* a,const void* b)
{
	long long x=*(long long*)a;long long y=*(long long*)b;
	if(x<y)return -1;return 1;
}
long long MIN(long long x,long long y)
{
	if(x<y)return x;return y;
}
int main()
{
	int n,m;
	long long a[1000001];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	qsort(a+1,n,sizeof(long long),cmp);
	long long ans=0,sum;
	for(int i=1;i<=m;i++)ans+=a[i];
	ans=a[m]*m-ans;
	int pos=1;sum=ans;
	for(int i=m+1;i<=n;i++)
	{
		sum=sum-(a[i-1]-a[i-m])+a[i]-a[i-1];
		ans=MIN(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}