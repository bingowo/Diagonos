#include<stdio.h>
#include<math.h>
long long convert(double n){  //重新定义强制类型转换，以弥补其精确度的不足 
	long long temp=(long long)n;
	if(fabs(n-temp)<1e-6) return temp;
	if(fabs(n-temp-1)<1e-6) return temp+1;
	if(fabs(n-temp+1)<1e-6) return temp-1;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int j=0;j<T;j++){
		long long n;
		scanf("%lld",&n);
		if(n==1) printf("1 is powerless.\n");
		else{
	    double m=(double)n;
		int key=0;
		printf("%lld",n);
		for(int i=2;i<=62;i++){
			double temp=pow(m,1.0/i);
			if(fabs(temp-convert(temp))>1e-6);
			else {
			      printf("=%lld^%d",convert(temp),i);
			      key=1;
				}
		}
		if(key==0) printf(" is powerless.",n);
		printf("\n");}
	}
} 