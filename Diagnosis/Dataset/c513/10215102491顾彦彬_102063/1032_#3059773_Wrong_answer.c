#include<stdio.h>
#include<stdlib.h>

int cmp1(const void*a,const void*b)
{
	long long int *x,*y;
	x=*(long long int(*)[0])a;
	y=*(long long int(*)[0])b;
	int i=0;
	while((x[i]==y[i])&&i<50)
	{
		i+=1;
	}
	return y[i]-x[i];
}

main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		long long int table[1000][51]={};
		for(int i=0;i<N;i++)
		{
			for (int j=0;j<51;j++)
			{
				scanf("%lld",&table[i][j]);
				if (table[i][j]==-1) break;
			}
		}
		qsort(table,N,sizeof(table[0]),cmp1);
		for(int i=0;i<=1000;i++)
		{
			for (int j=0;j<51;j++)
			{
				if (table[i][j]!=-1)
				{
					printf("%lld ",table[i][j]);
				}
				else
				{
					printf("\n");
					break;
				}
			}
		}
	}
	
}