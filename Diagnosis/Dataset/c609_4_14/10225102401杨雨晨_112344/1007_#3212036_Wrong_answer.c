#include <stdio.h>
#include<stdlib.h>
typedef struct{
	long long int a;
	int number;
}num;
int count(long long a)
{
	int i=0,c=0;
	for(;i<64;i++)
	{
		if(a>>i&1ll==1)c++;
	}
	return c;
}
int cmp(const void *a,const void *b)
{	int num1=(*(num*)a).number;int num2=(*(num*)b).number;
	if (num1-num2){return num2-num1;}
	else {return(*(num*)a).a-(*(num*)b).a;}
}
int main()
{
	int t,i,m,n,p;
	scanf ("%d",&t);
	for (i=0;i<t;i++)
	{	
		scanf("%d",&n);
		num *figure=(num*)malloc(n*sizeof (num));
		for (m=0;m<n;m++)
		{
			scanf("%lld",&figure[m].a);
			figure[m].number=count(figure[m].a);
		}
		qsort(figure,n,sizeof(num),cmp);
		printf("case #%d:\n",i);
		for(m=0;m<n;m++)
		{
			printf("%lld",figure[m].a);
		}
		printf("\n");
		free (figure);
	}
}