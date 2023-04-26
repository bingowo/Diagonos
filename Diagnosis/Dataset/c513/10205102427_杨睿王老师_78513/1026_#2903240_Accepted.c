#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int n,i;
	scanf("%d",&n);
	int * a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	unsigned long long int ans=0;
	for(i=n-1;i>=0;i=i-2){
		ans+=a[i];
		ans-=a[i-1];
	}
	printf("%lld",ans);
}