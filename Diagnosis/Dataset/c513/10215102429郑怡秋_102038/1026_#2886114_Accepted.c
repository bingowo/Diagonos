#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	long long* p1=(long long*)a;
	long long* p2=(long long*)b;
	if(*p1>*p2) return 1;
	else return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long A[100050];
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
	}
	qsort(A,n,sizeof(A[0]),cmp);
	int j=1;
	long long ans=0;
	while(j<n)
	{
		ans+=A[j]-A[j-1];
		j+=2;
	}
	printf("%lld",ans);
	return 0;
	
}