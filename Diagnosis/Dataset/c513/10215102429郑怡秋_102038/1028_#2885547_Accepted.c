#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h> 
int cmp(const void*a,const void*b)
{
	int* p1=(int*)a;
	int* p2=(int*)b;
	return *p1-*p2;
}
int main()
{
	char t;
	scanf("%c\n",&t);
	int A[210];
	int i=0;
	while(scanf("%d",&A[i++])!=EOF);
	i--;
	//printf("%d\n",i);
	//for(int j=0;j<i-1;j++) printf("%d\n",A[j]);
	for(int j=0;j<i;j++)
	{
		for(int k=j+1;k<i;k++)
		{
			if(A[j]==A[k])
			{
				A[j]=0;break;
			}
		}
	}
	int B[210];
	int r=0;
	for(int j=0;j<i;j++) 
	{
		if(A[j]!=0) B[r++]=A[j];
	}
	//for(int j=0;j<r-1;j++) printf("%d\n",B[j]);
	qsort(B,r,sizeof(B[0]),cmp);
	if(t=='A')
	{
		for(int j=0;j<r-1;j++) printf("%d ",B[j]);
		printf("%d\n",B[r-1]);}
	else if(t=='D')
	{
		for(int j=r-1;j>0;j--) printf("%d ",B[j]);
		printf("%d\n",B[0]);
	}
	return 0;
}