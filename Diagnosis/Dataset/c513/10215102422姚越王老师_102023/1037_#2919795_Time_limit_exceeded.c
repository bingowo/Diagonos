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
	long long max,tmp,ans=9223372036854775807;scanf("%d%d",&n,&m);
	long long a[n];
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	qsort(a,n,sizeof(long long),cmp);//降序排好
	for(i=0;i<=n-m;i++) 
	{
		max=a[i];tmp=0;
		for(j=i+1;j<i+m;j++)tmp+=max-a[j];
		ans=min(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}