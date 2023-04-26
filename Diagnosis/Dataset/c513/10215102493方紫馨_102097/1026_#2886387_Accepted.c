#include<stdio.h>
#include<stdlib.h>
int cmp(const void *p1,const void *p2){
	long long int a=*((long long int *)p1);
	long long int b=*((long long int *)p2);
	if(a>b)
		return 1;
	return -1;
}
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	long long int num[100000]={0};
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
		//printf("here");
	}
	qsort(num,n,sizeof(long long int),cmp);
	for(int i=0;i<n;i+=2){
		sum+=num[i+1]-num[i];
	}
	printf("%lld",sum);
	return 0;
}