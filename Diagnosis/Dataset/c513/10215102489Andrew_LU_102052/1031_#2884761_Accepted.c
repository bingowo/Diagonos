#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a, const void *b){
	return *(long long*)a>*(long long *)b;
}
int main(){
	int t,n,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		long long a[1005],b[1005];
		for(j=0;j<n;j++){
			scanf("%lld",&a[j]);
		}
		for(j=0;j<n;j++){
			scanf("%lld",&b[j]);
		}
		for(j=0;j<n;j++){
			//printf("qtest  %lld %lld\n",a[j],b[j]);
		}
		qsort((void *)a,n,sizeof(a[0]),cmp1);
		qsort((void *)b,n,sizeof(b[0]),cmp1);
		long long s=0;
		for(j=0;j<n;j++){
			//printf("%lld %lld\n",a[j],b[n-j-1]);
			s=s+a[j]*b[n-j-1];
		}
		printf("case #%d:\n%lld\n",i,s);
	}
}