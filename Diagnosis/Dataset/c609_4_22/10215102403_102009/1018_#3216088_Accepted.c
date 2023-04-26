#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void* b){
	return *((int*)a)-*((int*)b);
}
int main(){
	int n; long int a[100001];
	scanf("%d",&n); int i; 
	for(i=0;scanf("%ld",&a[i])!=EOF;i++);
	qsort(a,i,sizeof(a[0]),cmp);
	long int sum=0; i--;
	while(i>=0){
		sum+=(a[i]-a[i-1]);
		i-=2;
	}
	printf("%ld",sum);
	return 0;
}