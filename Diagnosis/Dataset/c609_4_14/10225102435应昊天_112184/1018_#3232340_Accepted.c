#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b);
int main(){
	int n;
	scanf("%d",&n);
	int arr[100000];
	for(int i = 0;i < n;i++){
		scanf("%d",&arr[i]);
	} 
	qsort(arr,n,sizeof(int),cmp);
	long long sum = 0;
	for(int i = 0;i < n-1;i += 2){
		sum += arr[i+1] - arr[i];
	}
	printf("%lld",sum);
	return 0;
}
int cmp(const void* a,const void* b){
	if(*(int*)a > *(int*)b)
		return 1;
	else
		return -1;
}