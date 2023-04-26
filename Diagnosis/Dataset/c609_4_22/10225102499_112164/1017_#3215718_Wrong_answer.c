#include <stdio.h>
#include <stdlib.h>

int cmp_A(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}
int cmp_D(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}

int main(){
	char order;
	int n;
	int a[100]={0};
	scanf("%c",&order);
	for(n=0;(scanf("%d",&a[n])!=EOF);n++);
	if(order=='A')
		qsort(a,n,sizeof(int),cmp_A);
	if(order=='D')
		qsort(a,n,sizeof(int),cmp_D);
	for(;n>0;n--){
		if(a[n]==a[n+1])
			continue;
		else printf("%d ",a[n]);
	}
	printf("%d",a[0]);
	return 0;
} 