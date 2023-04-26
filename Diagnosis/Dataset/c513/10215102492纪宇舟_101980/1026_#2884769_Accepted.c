#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void* a,const void* b)
{
	int x=*(int*)a;int y=*(int*)b;
	if(x<y)return -1;
	else return 1;
}
int main()
{
	int n;
	int a[100005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	qsort(a+1,n,sizeof(int),cmp);
	long long ans=0;
	for(int i=1;i<n;i+=2)ans+=a[i+1]-a[i];
	printf("%lld",ans);
	return 0;
}