#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n],i=0;
	while(scanf("%d",&a[i++])!=EOF);
	qsort(a,n,sizeof(int),cmp);
	int min=0;
	for(int j=0;j<n;j++){
		if(j%2==1)
            min=min+a[j]-a[j-1];
	}
	printf("%d",min);
	return 0;
}
