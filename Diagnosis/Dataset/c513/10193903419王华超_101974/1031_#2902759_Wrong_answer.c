#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define N 1000
int cmp1(const void *p1,const void *p2){
	return *((int*)p1)-*((int*)p2);
}
int cmp2(const void *p1,const void *p2){
	return *((int*)p2)-*((int*)p1);
}
int main(int argc, char *argv[]) {
	int t,cas;
	scanf("%d",&t);
	for(cas=0;cas<t;cas++){
		int n,i;
		scanf("%d",&n);
		int a[N],b[N];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		qsort(a,n,sizeof(a[0]),cmp1);
		qsort(b,n,sizeof(a[0]),cmp2);
		printf("# case%d\n",cas);
		int sum=0;
		for(i=0;i<n;i++){
			sum+=a[i]*b[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}