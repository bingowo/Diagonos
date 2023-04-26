#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n,m;
int A[1000005];
int cmp(const void* a,const void* b){
	return *(int *)a-*(int *)b;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	qsort(A+1,n,sizeof(int),cmp);
	unsigned long long ans,res=0;
	for(int i=1;i<=m;i++) res+=1ull*(A[m]-A[i]);
	ans=res;
	for(int i=m+1;i<=n;i++){
		res+=1ull*(A[i]-A[i-1])*m;
		res-=1ull*(A[i]-A[i-m]);
		if(res<ans) ans=res;
	}
	printf("%llu\n",ans);
	return 0;
}