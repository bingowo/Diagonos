#include<stdio.h>
#include<stdlib.h>

int order;

int cmp(const void *a,const void *b)
{
	return ((*(int*)a)-(*(int*)b))*order;
}

int main()
{
	int num[100],i,j,len=0;
	char ch;
	scanf("%c",&ch);
	if(ch=='A')order=1;
	else order=-1;
	while(~scanf("%d",&num[len++]));
	qsort(num,--len,sizeof(int),cmp);
	for(i=0;i<len;i++)if(i==len-1||num[i]!=num[i+1])printf("%d ",num[i]);
	return 0;
}