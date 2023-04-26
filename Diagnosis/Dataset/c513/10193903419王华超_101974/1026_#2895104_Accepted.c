#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000 
int cmp(const void *p1,const void *p2){
	int a=*((int*)p1),b=*((int*)p2);
	return (a-b);
}
int main()
{
	int n,*a;
	scanf("%d",&n);
	a=(int*)malloc(N*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	int sum=0;
	for(int i=0;i<n;i=i+2){
		sum+=a[i+1]-a[i];
	}
	free(a);
	printf("%d",sum);
}