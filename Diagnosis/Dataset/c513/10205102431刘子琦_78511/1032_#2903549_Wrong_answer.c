#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void*b)
{
	int* x;int*y;int i;
	x=(int*)a;y=(int*)b;
	for(i=0;i<51;i++)
	{
		if(x[i]<y[i])return 1;
		if(x[i]>y[i])return 0;
	}
	return 0;
}
int main()
{
	int i,t,j,n,m;int a[1000][51];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			j=0;
			while(scanf("%d",&m)&&m!=-1)
				a[i][j++]=m;
			a[i][j]=m;
		}
		qsort(a,n,sizeof(a[0]),comp);
		for(m=0;m<n;m++)
		{
			for(j=0;a[m][j]!=-1;j++)			
				printf("%d ",a[m][j]);			
			printf("\n");
		}
	}
	return 0;
}