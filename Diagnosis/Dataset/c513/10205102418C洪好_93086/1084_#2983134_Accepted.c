#include<stdio.h> 
int f(int x)
{
	int i,a=1;
	for(i=0;i<x;i++)
		a*=2;
	return a;
}
int main()
{
	int T,N,a[10],i;
	scanf("%d",&T);
	for(i=0;i<T;i++)
		scanf("%d",&a[i]);
	for(i=0;i<T;i++)
	{
		N=f(a[i]);
		printf("case #%d:\n%d\n",i,N);
	}		
} 