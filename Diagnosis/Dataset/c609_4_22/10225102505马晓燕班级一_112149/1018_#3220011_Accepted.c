#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
	return *((int *)a) - *((int *)b);
}
int main()
{
	int n;
	scanf("%d",&n);
	int *p = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",p+i);
	}
	qsort(p,n,sizeof(int),cmp);
	int sum=0;
	for(int i=0;i<=n-2;i+=2){
		sum = sum + p[i+1] - p[i];
	}
	printf("%d",sum);
	return 0;
}
