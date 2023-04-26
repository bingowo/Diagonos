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
	long long int sum,min=1e15;
	for(int i=0;i+m<=n;i++){
		sum=0;
		for(int j=i+1;j<i+m;j++){
			sum+=a[i]-a[j];
		}
		//printf("%d\n",sum);
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
		scanf("%d",&NUM[i]);
	}
	qsort(NUM,n,sizeof(long long int),cmp);
	int min = calculation(NUM,n,m);
	printf("%lld",min);
	return 0;
}