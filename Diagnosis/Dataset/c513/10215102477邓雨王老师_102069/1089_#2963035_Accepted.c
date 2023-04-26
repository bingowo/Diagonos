//这题运用同余定理   即(a*b)%c=(a%c*b%c)%c 
#include<stdio.h>
#include<string.h>
long long solve(int a,int b,int n){   //返回余数  ,这里的n=10^N 
	long long sum=1;
	int i;
	for(i=0;i<b;i++){
		sum=(sum*(a%n))%n; 
	}
	return sum; 
}
int pd(long long a){  //用来判断a的位数 
	int count=0;
	if(a==0) return 1;
	while(a>0){
		a/=10;
		count++;
	} 
	return count;
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	int a,b,N,n=1;
	for(i=0;i<chance;i++){
		scanf("%d%d%d",&a,&b,&N);
		int j;
		for(j=0;j<N;j++){
			n=n*10;
		}
		printf("case #%d:\n",i);
		if(pd(solve(a,b,n))<N){
			for(j=0;j<N-pd(solve(a,b,n));j++){
				printf("0");
			}
		}
	    printf("%lld\n",solve(a,b,n));
	    n=1;
	}
	return 0;
} 