#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
int main(){
	int n=0;
	scanf("%d",&n);
	int a[n];
	int i=0;
	while(scanf("%d",&a[i++])!=EOF);
	qsort(a,n,sizeof(a[0]),cmp);
	int minsum=0;
	for(int b=0;b<n;b++){
		if(b%2==1) minsum=minsum+a[b]-a[b-1];
	}
	printf("%d",minsum);
	return 0;
}