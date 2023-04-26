#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	int c=*(int*)a;
	int d=*(int*)b;
	return(c-d);
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[110000]={0};
	int min=0,j=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	while(j<n)
	{
		min+=abs(a[j]-a[j+1]);
		j=j+2;
	}
	printf("%d",min);
}