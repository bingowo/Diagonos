#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	int p,q;
	p=*(int*)a;q=*(int*)b;
	return p-q;
}
int main()
{
	int n,i,a[15]={0},sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) sum+=a[i];
	qsort(a,n,sizeof(a[0]),cmp);
	char s[1001],j;
	int su[1000]={0};
	su[0]=1;
	for(i=0;i<n;i++)
	{
		for(j=100;j>=0;j--)
		{
			if(su[j]>0) su[j+a[i]]++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=100;j++)
		{
			if(su[j]>0&&j-a[i]>0) su[j-a[i]]++;
		}
	}
	int k=0;
	for(i=1;i<=sum;i++)
	{
		if(su[i]>0) s[k++]='1';
		else s[k++]='0';
	}
	s[k]='\0';
	printf("%s\n",s);
	
	
	return 0;
}