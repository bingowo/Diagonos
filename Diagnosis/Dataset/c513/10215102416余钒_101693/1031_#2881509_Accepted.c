#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n,A[10005],B[10005];
int cmp(const void* a,const void* b){
	int x=*(int*)a,y=*(int*)b;
	return x-y;
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++) scanf("%d",&B[i]);
		qsort(A+1,n,sizeof(int),cmp);
		qsort(B+1,n,sizeof(int),cmp);
		printf("case #%d:\n",c);
		long long ans=0;
		for(int i=1;i<=n;i++) ans+=A[i]*B[n-i+1];
		printf("%lld\n",ans);
	}
	return 0;
}