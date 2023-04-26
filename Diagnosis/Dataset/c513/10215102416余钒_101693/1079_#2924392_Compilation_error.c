#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[1005],cnt;
long long sum[1000005];

int cmp(const void* a,const void *b){
	long long x=*(long long*)a,y=*(long long *)b;
	if(x>y) return 1;
	else if(x<y) return -1;
	else return 0;
}

int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		a[0]=0,cnt=0;
		for(int i=1;i<=n;i++) a[i]+=a[i-1];
		for(int i=1;i<=n;i++)
			for(int j=1;j+i-1<=n;j++)
				sum[++cnt]=a[j+i-1]-a[i-1];
		qsort(sum+1,cnt,sizeof(long long),cmp);
		sum[0]=0;
		for(int i=1;i<=cnt;i++) sum[i]+=sum[i-1];
		int L,R;
		printf("case #%d:\n",c);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&L,&R);
			printf("%lld ",sum[R]-sum[L-1]);
		}
		puts("");
	}
	return 0;
} 