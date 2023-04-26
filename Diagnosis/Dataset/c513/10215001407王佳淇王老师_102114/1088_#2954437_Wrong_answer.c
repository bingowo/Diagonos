#include<stdio.h>
long long jc(int n){
    long long sum=1;
    if(n==0) return sum; 
    for(int i=n;i>0;i--)
	{
		sum*=i;
	}
	return sum;
	}
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		printf("case #%d:\n",v);
		int m,n;
		scanf("%d %d",&m,&n);
		long long a=jc(m);
		long long b=jc(n);
		long long c=jc(m-n);
		printf("%lld\n",(a/b)/c);
	}
	return 0;
}	