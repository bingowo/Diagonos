#include<stdio.h>
#include<stdlib.h>
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
	char c=getchar();
	int a[100],i,j;
	for(i=0;~scanf("%d",&a[i]);i++);
	if(c=='A')qsort(a,i,sizeof(a[0]),cmp1);
	else qsort(a,i,sizeof(a[0]),cmp2);
	for(j=0;j<i;j++)
	{
		if(j==0)printf("%d ",a[j]);
		else if(a[j]!=a[j-1])printf("%d ",a[j]);
	}
	return 0;
}