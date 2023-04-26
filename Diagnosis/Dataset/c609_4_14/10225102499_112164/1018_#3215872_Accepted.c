#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}

int main(){
	int n,i;
	long long sum=0;
	int a[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	for(i=0;i<n-1;i+=2){
		sum+=a[i+1]-a[i];
	}
	printf("%lld",sum);
}