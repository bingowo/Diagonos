#include<stdio.h>
#include<stdlib.h>
int cmp(const void* p1,const void* p2){
	long long int a = *((long long int*)p1);
	long long int b = *((long long int*)p2);
	if(a>b)
		return -1;
	return 1;
}
long long calculation(long long int a[],int n,int m){
	//long long int ret[n];
	long long int sum,min=0;
	sum=0;
	for(int j=0;j<m;j++){
		sum+=a[0]-a[j];
	}
	min = sum; 
	for(int i=1;i+m<=n;i++){
		sum = sum - (m - 1) * a[i - 1] + m * a[i] - a[i + m - 1];
		if(sum<min)
			min=sum;
	}
	return min;
}
int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	long long int NUM[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&NUM[i]);
	}
	qsort(NUM,n,sizeof(long long int),cmp);
	long long int min = 0;
	min = calculation(NUM,n,m);
	printf("%lld",min);
	return 0;
}