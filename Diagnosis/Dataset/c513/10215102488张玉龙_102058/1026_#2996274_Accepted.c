#include<stdio.h>
#include<malloc.h>

int cmp(const void*a, const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,sum=0,i;
	scanf("%d",&n);
	int*v=malloc(1000000*sizeof(int));
	int*p=v;
	for(i=0;i<n;i++)
	{
		scanf("%d",p++);
	}
	qsort(v,n,sizeof(int),cmp);
	for(i=0;i<n;i+=2)
	{
		sum+=(v[i+1]-v[i]);
	}
	printf("%d\n",sum);
	free(v);
	return 0;
}