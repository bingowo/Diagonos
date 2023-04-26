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
	//for(i=0;i<n;i++)printf("%lld ",a[i]) ;
	//printf("\n");
	long long ans=0,max,len=9223372036854775807;
	for(i=0;i<=n-m;i++)
	{
		ans=0;
		max=a[i+m-1];
		for(j=i;j<i+m-1;j++)
		{
			ans+=max-a[j];
		}
		if(ans<len)len=ans;
	}
	printf("%lld",len);
	return 0;
}