#include <stdio.h>
#include <stdlib.h>
long long num[1000001];
int cmp(const void* a,const void* b)
{
	long long x,y;
	x=*(long long*)a;
	y=*(long long*)b;
	if(x<y){
		return -1;
	}
	return 1;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for (i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	qsort(num+1,n,sizeof(num[1]),cmp);
	long long sum=0,ans=0;
	for (i=1;i<=m;i++){
		sum+=num[m]-num[i];
	}
	ans=sum;
	for (i=m+1;i<=n;i++){
		sum+=(num[i]-num[i-1])*m;
		sum-=(num[i]-num[i-m]);
		if(sum<ans){
			ans=sum;
		}
	}
	printf("%lld\n",ans);
	return 0;
 } 