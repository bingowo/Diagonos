#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	char*p1=(char*)a;char*p2=(char*)b;
	int l1=strlen(p1),l2=strlen(p2);
	int j1=l1,j2=l2;
	//printf("%d %d\n",l1,l2);
	for(int i=0;i<l1;i++)
	{
		for(int j=i+1;j<l1;j++)
		{
			if(p1[i]==p1[j]) j1--;
		}
	}
	for(int i=0;i<l2;i++)
	{
		for(int j=i+1;j<l2;j++)
		{
			if(p2[i]==p2[j]) j2--;
		}
	}
	//printf("%d %d\n",j1,j2);
	if(j1>j2) return -1;
	else if(j1<j2) return 1;
	else 
	{
		for(int i=0;i<l1;i++)
		{
			if(p1[i]<p2[i]) return -1;
			else if(p1[i]>p2[i]) return 1;
		}
	}
	
}


int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		char A[100][110];
		for(int j=0;j<n;j++)
		{
			scanf("%s",A[j]);
		}
		qsort(A,n,sizeof(A[0]),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<n;k++)
		{
			printf("%s\n",A[k]);
		}
	}
	return 0;
}