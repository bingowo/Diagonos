#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1,const void *p2)
{
	long long int n1=*(long long int*)p1,n2=*(long long int*)p2,one=1;
	int r1=0,r2=0,i;
	for(i=0;i<64;i++)
	{
		r1+=((n1>>i)&one);
		r2+=((n2>>i)&one);
	}
	if(r1!=r2)return r2>r1?1:-1;
	if(n1!=n2)return n2>n1?-1:1;
	return 0;
}

int main()
{
	int c,cases,n;
	long long int *arr=NULL;
	int i,j;
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		scanf("%d",&n);
		arr=(long long int*)malloc(n*sizeof(long long));
		for(i=0;i<n;i++)scanf("%lld",(arr+i));
		qsort(arr,n,sizeof(long long),cmp);
		printf("case #%d:\n",c);
		for(i=0;i<n;i++)printf("%lld%c",*(arr+i),i!=n-1?' ':(c!=cases-1?'\n':'\0'));
		free(arr);
	}
	return 0;
}