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
	long long ans=0,l,len=9223372036854775807,s;
	for(i=0;i<=n-m;i++)
	{
		l=a[i+m-1]-a[i];
		//printf("i=%d l=%lld ",i,l);
		if(l<len)
		{
			len=l;
			s=i+m-1;
		}
		//printf("len=%lld s=%d\n",len,s);
	}
	for(i=s-m+1,j=0;j<m-1;i++,j++)
	{
		ans+=a[s]-a[i];
	}
	printf("%lld",ans);
	return 0;
}