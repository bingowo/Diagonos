#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
	long long p1=*(long long*)a,p2=*(long long*)b;
	if(p1>p2)return 1;
	else return -1;
}
int main()
{
	int n,m,i,j;scanf("%d%d",&n,&m);
	long long a[n];
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	qsort(a,n,sizeof(long long),cmp);
	long long ans=0,max=a[m-1];
	for(i=0;i<m-1;i++)
	{
		ans+=max-a[i];
	}
	printf("%lld",ans);
	return 0;
}