#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp1(const void *a, const void *b){
	return *(long long *)a>*(long long *)b;
}
int main(){
	int n,i;
	long long a[100005];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	long long sum=0;
	for(i=0;i<n;i+=2){
		sum+=a[i+1]-a[i];
	}
	printf("%lld",sum);
}