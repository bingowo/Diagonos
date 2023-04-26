#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int getmax(long long n)
{
	int i;
	if(n<0)n=-n;
	if(n==0)return 0;
	while(n>=10)n=n/10;
	i=n;
	return i;
}

int cmp(const void *a,const void *b)
{
	long long n1=*(long long*)a,n2=*(long long*)b;
	if(getmax(n1)!=getmax(n2))return getmax(n2)-getmax(n1);
	if(n1>n2)return 1;
	if(n1<n2)return -1;
	return 0;
}

int main()
{
	int i,j,k;
	int len=0;
	int c,cases;
	long long num[10000];
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		scanf("%d",&len);
		for(i=0;i<len;i++)scanf("%lld",&num[i]);
		qsort(num,len,sizeof(long long),cmp);
		printf("case #%d:\n",c);
		for(i=0;i<len;i++)
		{
			printf("%lld",num[i]);
			if(i!=len-1)putchar(' ');
		}
		if(c!=cases-1)putchar('\n');
	}
	return 0;
}