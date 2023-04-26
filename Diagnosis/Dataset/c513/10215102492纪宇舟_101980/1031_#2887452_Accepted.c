#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void* a,const void* b)
{
	long long x=*(long long*)a;long long y=*(long long*)b;
	if(x<y)return -1;
	return 1;
}
int main()
{
	int ct=0,T;scanf("%d\n",&T);
	long long a1[1005],a2[1005];
	while(T--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a1[i]);
		for(int i=1;i<=n;i++)scanf("%lld",&a2[i]);
		qsort(a1+1,n,sizeof(long long),cmp);
		qsort(a2+1,n,sizeof(long long),cmp);
		long long ans=0;
		for(int i=1;i<=n;i++)ans+=a1[i]*a2[n-i+1];
		//for(int i=1;i<=n;i++)printf("%lld ",a1[i]);printf("\n");for(int i=1;i<=n;i++)printf("%lld ",a2[i]);printf("\n");
		printf("case #%d:\n",ct++);
		printf("%lld\n",ans);
	}
	return 0;
}