#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int cmp(const void *p1,const void *p2){
	long long a=*((long long*)p1),b=*((long long*)p2);
	if (a>b){
		return 1;
	}
	else{
		return -1;
	}
}
int main()
{
	int n,m;
	long long *a;
	scanf("%d %d",&n,&m);
	a=(long long*)malloc(n*sizeof(long long));
	for(int i=0;i<n;i++){
		scanf("%lld",a+i);
	}
	long long min=LLONG_MAX;
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<n-m+1;i++){
		long long sum=0;
		for(int j=i;j<m+i;j++){
			sum+=a[m+i-1]-a[j];
		}
		if (sum<min) min=sum;
	}
	printf("%lld",min);
	free(a);
	return 0;
}