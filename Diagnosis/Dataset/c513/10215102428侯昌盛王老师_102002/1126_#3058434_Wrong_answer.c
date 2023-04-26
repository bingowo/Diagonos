#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	long long *q,*p;
	q=(long long*)a;
	p=(long long*)b;
	if(*q>*p) return 1;
	else return -1;
	
}
int main()
{
	int n;
	scanf("%d",&n);
	long long a[10000];
	int i=0;
	for(i;i<n;i++) scanf("%lld",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	long long res=0,sum=0;
	for(i=0;i<n;i++) 
	{
		res^=a[i];
		sum+=a[i];
	}
	if(res) printf("-1\n");
	else{
		sum=sum-a[0];
		printf("%lld\n",sum);
	}
	return 0;
}