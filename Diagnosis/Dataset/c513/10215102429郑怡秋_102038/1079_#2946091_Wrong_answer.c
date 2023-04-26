#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	int* p1=(int*)a;int* p2=(int*)b;
	return *p1-*p2;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int *A=(int*)malloc(n*sizeof(int));
		for(int j=0;j<n;j++) scanf("%d",&A[j]);
		//printf("%d%d ",n,m);
		int B[1000001]={0};int x=0;
		for(int j=0;j<n;j++) B[x++]=A[j];
//		for(int j=0;j<n-1;j++) B[x++]=B[j]+A[j+1];
//		for(int j=0;j<n-2;j++) B[x++]=B[j+n]+A[j+2];
		int j3=1;int x0=0;
		for(int j1=n-1;j1>=1;j1--)
		{
			if(j1<=n-2) x0+=n-j3+2;
			for(int j2=0;j2<j1&&j3+j2<=n;j2++)
			{
				if(j1<=n-2) B[x++]=B[j2+x0]+A[j2+j3];
				else if(j1>n-2) B[x++]=B[j2]+A[j2+j3];
				//printf("%d\n",B[x-1]);
			}
			
			j3++;
		}
		qsort(B,x,sizeof(B[0]),cmp);
		
		printf("case #%d\n",i);
		for(int j=0;j<m;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			long long  sum=0;
			for(int j1=a-1;j1<b;j1++)
			{
				sum+=B[j1];
			}
			printf("%lld\n",sum);
		 } 
		
		free(A);
	}
	return 0;
}