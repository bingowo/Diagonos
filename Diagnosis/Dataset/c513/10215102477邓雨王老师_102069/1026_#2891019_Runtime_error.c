#include<stdio.h>
#include<math.h>
int cmp(const void*a,const void*b){
	long long x,y;
	x=*(long long*)a;
	y=*(long long*)b;
	if(x>y) return 1;
	else return -1;
}
int main(){
	int n;
	scanf("%d",&n);
	int i;
	long long a[20000];
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	qsort(a,n,sizeof(long long),cmp);
	long long sum=0;
	for(i=0;i<(n+1)/2;i++){
		sum=sum+a[2*i+1]-a[2*i];
	}
	printf("%lld",sum);
}