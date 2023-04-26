#include <stdio.h>
#include <stdlib.h>
int cmp1(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}
int cmp2(const void* a,const void* b)
{
	return *(int*)b-*(int*)a;
}

int main()
{
	int T;
	scanf("%d",&T);
	int i,n;
	int a[1000],b[1000];
	for(i=0;i<T;i++){
		scanf("%d",&n);
		int j;
		for (j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		for (j=0;j<n;j++){
			scanf("%d",&b[j]);	
		}
		qsort(a,n,sizeof(a[0]),cmp1);
		qsort(b,n,sizeof(b[0]),cmp2);
		long long sum=0;
		for (j=0;j<n;j++){
			sum+=a[j]*b[j];
		}
		printf("case #%d:\n",i);
		printf("%lld\n",sum);
	}
	return 0;
}