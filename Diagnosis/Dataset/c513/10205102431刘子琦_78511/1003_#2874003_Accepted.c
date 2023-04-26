#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	long long int p=*(long long int*)a;
	long long int q=*(long long int*)b;
	int i,j,k;
	j=k=0;
	for(i=63;i>=0;i--)
	{
		if(p>>i&1==1)j++;
		if(q>>i&1==1)k++;
	}
	if(j!=k)return k-j;
	else return p>q?1:-1;	
} 
int main()
{
	int t,i,n,j;long long int a[10000],m;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{		
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%ld",&m);
			a[j]=m;
		}
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)
			printf("%ld ",a[j]);
		printf("\n");
	}
	return 0;
}