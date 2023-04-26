#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int T,n,m;
long long a[1010] = {0};
long long pre[1010] = {0};
long long b[500555] = {0};
long long preb[500555] = {0};
int mycmp(const void *aa, const void *bb)
{
	long long a = *(long long*)aa;
	long long b = *(long long*)bb;
	if(a>b) return 1;
	else return -1;
}
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		scanf("%d %d",&n,&m);
		memset(a,0,sizeof(a));
		memset(pre,0,sizeof(pre));
		memset(b,0,sizeof(b));
		memset(preb,0,sizeof(preb));
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) pre[i] = pre[i-1]+a[i];
		int idx = 0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				idx++;
				b[idx] = pre[j]-pre[i-1];
			}
		}
		qsort(b+1,idx,sizeof(b[0]),mycmp);
		printf("case #%d:\n",kase);
		for(int i=1;i<=idx;i++)
			preb[i] = preb[i-1]+b[i];
		for(int i=1;i<=m;i++)
		{
			int l,u;
			scanf("%d %d",&l,&u);
			long long res = preb[u]-preb[l-1];
			printf("%lld\n",res);
		}
	}
	return 0;
}