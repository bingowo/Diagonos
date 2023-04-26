#include<stdio.h>
#include<stdlib.h> 
int main()
{
    int a[1010]={0};
	a[0]=1;
	int type[]={4,2,3,1};
	for(int i=0;i<4;i++)
	{
	for(int j=type[i];j<=1000;j++)
	a[j]+=a[j-type[i]];
}
	int T,x;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&x);
		printf("case #%d:\n%d\n",i,a[x]);	
	}
	return 0;
} 