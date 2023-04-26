#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h> 
int cmp(const void*a,const void*b)
{
	int *p1=(int*)a;
	int *p2=(int*)b;
	return *p1-*p2;
}


int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int A[1010];
		int B[1010];
		int n=0;
		scanf("%d",&n);
		int a=0,b=0;
		for(;a<n;a++) {scanf("%d",&A[a]);}
		for(;b<n;b++) {scanf("%d",&B[b]);}
		int ans=0;
		qsort(A,n,sizeof(A[0]),cmp);
		qsort(B,n,sizeof(B[0]),cmp);
		int c=0,d=n-1;
		for(;c<n;c++,d--) ans+=A[c]*B[d];
		printf("case #%d:\n%d\n",i,ans);
	}
	return 0;
}