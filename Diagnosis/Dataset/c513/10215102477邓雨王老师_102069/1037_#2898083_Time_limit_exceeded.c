#include<stdio.h>
int cmp(const void*a,const void*b){
	long long x,y;
	x=*(long long*)a;
	y=*(long long*)b;
	if(x>y) return 1;
	else return -1;
} 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	long long a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	qsort(a,n,sizeof(long long),cmp);
    long long b[n-m+1];
    for(i=0;i<n-m+1;i++){
    	long long sum=0;
    	int j=i;
    	for(;j<i+m-1;j++){
    		sum=sum+a[i+m-1]-a[j];
		}
		b[i]=sum;
	}
	qsort(b,n-m+1,sizeof(long long),cmp);
	printf("%lld",b[0]);
}