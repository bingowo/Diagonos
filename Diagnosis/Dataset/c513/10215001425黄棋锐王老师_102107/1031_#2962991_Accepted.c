#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int xcmp(const void*a,const void *b)
{   return *(int*)a-*(int*)b;
}
int dcmp(const void*a,const void*b)
{
	return *(int*)b-*(int*)a;
}
 int main()
 {  int k,T,n;
 	scanf("%d\n",&T);
	 for(k=0;k<T;k++)
	 {  scanf("%d\n",&n);
	 	int*a;
	 	int*b;
	 	a=(int*)malloc(sizeof(int)*n);
	 	b=(int*)malloc(sizeof(int)*n);
	 	int i=0;
	 	for(i=0;i<n;i++) scanf("%d",&a[i]);
	 	for(i=0;i<n;i++) scanf("%d",&b[i]);
	 	qsort(a,n,sizeof(int),xcmp);
	 	qsort(b,n,sizeof(int),dcmp);
	 	long long muti=0;
	 	for(i=0;i<n;i++) muti+=a[i]*b[i];
	 	printf("case #%d:\n",k);
	 	printf("%lld\n",muti);
	 	free(a);
	 	free(b);
	 } 
		return 0;
}