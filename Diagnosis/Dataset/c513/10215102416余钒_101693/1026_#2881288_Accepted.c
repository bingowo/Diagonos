#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,T,A[100005]; 

int cmp(const void* a,const void* b){
	int x=*(int *)a,y=*(int *)b;
	return x-y;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	qsort(A+1,n,sizeof(int),cmp);
	long long ans=0;
	for(int i=1;i<=n/2;i++)
		ans+=A[i*2]-A[i*2-1];
	printf("%lld\n",ans);
	return 0;
}