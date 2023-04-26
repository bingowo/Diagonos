#include <stdio.h>
#include<stdlib.h>
int T,a[100001],book[1000],n,i;
long long sum;
int cmp(const void *e1,const void *e2)
{
	int k1=*(int*)e1,k2=*(int*)e2,a=abs(k1),b=abs(k2);
	int cnta=0,cntb=0;
	do
	{
		a/=10;
		cnta++;
	}while(a);
	do
	{
		b/=10;
		cntb++;
	}while(b);
	if(cnta!=cntb)
		return cntb-cnta;
	else
		return k1-k2;
}
int main()
{
	while(scanf("%d",&a[i++])==1)
		char c=getchar();
	n=i;
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}