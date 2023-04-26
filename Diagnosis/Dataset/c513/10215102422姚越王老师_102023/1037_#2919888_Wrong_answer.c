#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
	long long p1=*(long long*)a,p2=*(long long*)b;
	if(p1<p2)return 1;
	else return -1;
}
long long min(long long a,long long b)
{
	if(a<b)return a;
	else return b;
}
int main()
{
	int n,m,i,j;
	long long max,ans;scanf("%d%d",&n,&m);
	long long a[n];
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	qsort(a,n,sizeof(long long),cmp);//降序排
	max=a[0];ans=0;
	for(j=1;j<m;j++)ans+=max-a[j];
	for(i=1;i<=n-m;i++) 
	{
		ans=min(ans,ans-(m-1)*a[i-1]+m*a[i]-a[i+m-1]);
	}
	printf("%lld",ans);
	return 0;
}