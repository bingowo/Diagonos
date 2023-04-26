#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
	const unsigned long long l1=*(long long*)a,l2=*(long long*)b;
	if(l1==l2)return 0;
	return l1>l2?-1:1;
}

int main()
{
	int i,j=0,k;
	long long nums,numc;
	unsigned long long result=0,maxresult=0,*numlist;
	
	scanf("%lld %lld",&nums,&numc);
	numlist=(unsigned long long*)malloc(nums*sizeof(unsigned long long));
	for(i=0;i<nums;i++)scanf("%llu",numlist+i);
	qsort(numlist,nums,sizeof(unsigned long long),cmp);
	result+=(*numlist)*(numc-1);
	for(i=1;i<numc;i++)result-=*(numlist+i);
	maxresult=result;
	for(i=1;i<nums-numc+1;i++)
	{
		result-=(*(numlist+i-1)-(*(numlist+i)))*(numc-1);
		result=result-(*(numlist+numc+i-1))+(*(numlist+i));
		
		
		
		
		if(result<maxresult)maxresult=result;
	}
	printf("%llu",maxresult);
	free(numlist);
	return 0;
}