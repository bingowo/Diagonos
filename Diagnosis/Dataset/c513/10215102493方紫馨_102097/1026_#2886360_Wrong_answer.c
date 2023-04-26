#include<stdio.h>
#include<stdlib.h>
int cmp(const void *p1,const void *p2){
	int a=*((int *)p1);
	int b=*((int *)p2);
	if(a>b)
		return 1;
	return -1;
}
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	long long int num[100000];
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	qsort(num,n,sizeof(int),cmp);
	for(int i=0;i<n;i+=2){
		sum+=num[i+1]-num[i];
	}
	printf("%lld",sum);
	return 0;
}