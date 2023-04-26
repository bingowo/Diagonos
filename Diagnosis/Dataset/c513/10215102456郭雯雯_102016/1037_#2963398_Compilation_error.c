#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int cmp(const void* a,const void* b){
	long long x=*(long long*)a,y=*(long long*)b;
	if(x>y) return 1;
	else return -1;
}
int main() {
	int T,n,m;
    scanf("%d%d",&n,&m)；
    long long A[n+1];
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	qsort(A+1,n,sizeof(long long),cmp);
	long long ans,res=0;
	for(int i=1;i<=m;i++) res+=A[m]-A[i];
	ans=res;
	for(int i=m+1;i<=n;i++){
		res+=(A[i]-A[i-1])*m;
		res-=(A[i]-A[i-m]);
		if(res<ans) ans=res;
	}
	printf("%lld\n",ans);
	return 0;
}