#include<stdio.h>
#include<stdlib.h> 

int cmp(const void* p1,const void* p2){
	long long int a = *((long long int*)p1);
	long long int b = *((long long int*)p2);
	if(a>b)
		return 1;
	return -1;
}

int main()
{
	int n;
	long long int num[100000];
	scanf("%d",&n); 
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	qsort(num,n,sizeof(int),cmp);
	long long int sign=-1,ret=0;
	for(int i=0;i<n;i++){
		ret+=sign*num[i];
		sign*=-1; 
	}
	printf("%lld",ret);
	return 0;
}