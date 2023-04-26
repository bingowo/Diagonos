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
	long long n,m;
	long long a[1000001];
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	qsort(a+1,n,sizeof(long long),cmp);
	long long ans=0,sum=0;
	for(int i=1;i<=m;i++)sum+=a[i];
	ans=a[m]*m-sum;
	for(int i=m+1;i<=n;i++)
	{
		sum=sum+a[i]-a[i-m];
		ans=MIN(ans,a[i]*m-sum);
	}
	printf("%lld",ans);
	return 0;
}