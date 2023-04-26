#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 1001
int cmp(const void*a,const void*b)
{
	int*c=(int*)a;
	int*d=(int*)b;
	int i=0;
	while(c[i]==d[i]&&c[i]!=-1)
	{
		i++;
	}
	if(c[i]>d[i])
	{
		return -1;
	}
	else{
		return 1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		int a[M][51];
		memset(a,-1,sizeof(a));
		int j=0,t=0;
		for(j=0;j<N;j++)
		{
			t=0;
			int temp;
			scanf("%d",&temp);
			while(temp!=-1)
			{
				a[j][t]=temp;
				t++;
				scanf("%d",&temp); 
			}
		}
		/*for(j=0;j<N;j++)
		{
			t=0;
			while(a[j][t]!=-1)
			{
				printf("%d ",a[j][t]);
			}
			printf("\n");
		}*/
		qsort(a,N,sizeof(a[0]),cmp);
		for(j=0;j<N;j++)
		{
			t=0;
			while(a[j][t]!=-1)
			{
				printf("%d ",a[j][t]);
				t++;
			}
			printf("\n");
		}
	}
}