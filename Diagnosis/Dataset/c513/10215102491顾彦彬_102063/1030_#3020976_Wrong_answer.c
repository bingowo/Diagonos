#include<stdio.h>
#include<stdlib.h>

int cmp1(const void *a,const void *b)
{
	long long int x=*(long long int*)a;
	long long int y=*(long long int*)b;
	long long int m=x,n=y;
	if(x<0) x=-x;
	if(y<0) y=-y;
	int resx=0,resy=0;
	while(x>0)
	{
		resx=x%10; 
		x=x/10;
	}
	while(y>0)
	{
		resy=y%10;
		y=y/10;
	}
	if(resx!=resy)
		return resy-resx;
	else
		return m-n;
}

int main()
{
	int T,N;
	long long int input[10000];
	scanf("%d",&T);
	int k=0;
	while(T--)
	{
		scanf("%d",&N);
		int i=0;
		while(N--)
		{
			scanf("%lld",&input[i++]); 
		}
		qsort(input,i,sizeof(input[0]),cmp1);
		printf("case #%d:\n",k++);
		for(int j=0;j<i;j++)
		{
			printf("%lld ",input[j]);
		}
		printf("\n");
	}
}