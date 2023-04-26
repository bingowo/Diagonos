#include <stdio.h>
int f(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
int main(){
	int n,i;scanf("%d",&n);
	int num[n],ret=0;
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	qsort(num,n,sizeof(int),f);
	for(i=1;i<n;i+=2){
		ret+=num[i]-num[i-1];
	}
	printf("%d",ret);
}