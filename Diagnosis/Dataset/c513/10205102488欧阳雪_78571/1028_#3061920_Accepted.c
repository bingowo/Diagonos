#include<stdio.h>
#include<stdlib.h>
int cmp1(const void*a,const void*b)
{
	return (*(int*)a - *(int*)b);
}
int cmp2(const void*a,const void*b)
{
	return (*(int*)b - *(int*)a);
}
int main()
{
	char c;
	scanf("%c",&c);
	int a[101]={0};
	int i=0,n=0;
	while(scanf("%d",&a[i])!=EOF)
	{
		i++;
		n++;
	}
//	printf("n:%d\n",n); 
	if(c=='A')
	{
		qsort(a,n,sizeof(a[0]),cmp1);
	}
	if(c=='D')
	{
		qsort(a,n,sizeof(a[0]),cmp2);
	}
	i=0;
	while(i<n)
	{
		while(a[i]==a[i+1]&&i+1<n)
		{
			i++;
		}
		printf("%d ",a[i]);
		i++;
	}
}