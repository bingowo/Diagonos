#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	qsort(a,n,sizeof(a[0]),cmp);
	long long sum=0;
	for(int i=0;i<m;i++){
		sum+=a[m-1]-a[i];
	}
	printf("%lld",sum);
	free(a);
	return 0;
}