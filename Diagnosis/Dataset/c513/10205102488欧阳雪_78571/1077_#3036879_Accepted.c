#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
	int c=*(int *)a;
	int d=*(int *)b;
	if(c>=d)
	{
		return 1;
	}
	else{
		return -1;
	}
}
int main() 
{
	int m,n;
	int A[1000]={0},B[1000]={0},C[1000]={0};
	int flg[1000]={0},ans1[1000]={0};
	scanf("%d",&m);
	int i=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&A[i]);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&B[i]);
	}
	int j=0,j1=0,j2=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i]==B[j]&&flg[j]!=-1)
			{
				ans1[j1]=B[j];
				j1++;
				flg[j]=-1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(flg[i]!=-1)
		{
			C[j2]=B[i];
			j2++;
		}
	}
	qsort(C,j2,sizeof(C[0]),cmp);
	for(i=0;i<j1;i++)
	{
		printf("%d ",ans1[i]);
	}
	for(i=0;i<j2;i++)
	{
		printf("%d ",C[i]);
	}
	return 0;
}