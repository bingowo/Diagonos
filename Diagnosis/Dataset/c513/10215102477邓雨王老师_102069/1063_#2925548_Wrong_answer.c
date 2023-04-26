#include<stdio.h>
long long GCD(long long m,long long n)
{
    if(m%n==0){  //若成立，则说明m>=n,且n是m的一个约数 
        return n;
    }
    return GCD(n,m%n);
    
}
int main(){
	long long x,y;
	scanf("%lld %lld",&x,&y);
	long long sum=0;
	long long gs;
	if(x%y==0){
		gs=x/y;
		sum=4*y*(x/y);
	}
	else{
		long long p=GCD(x,y);
		long long temp=x;
		long long temp1=GCD(x,y);   //temp1即为最大公约数 
		x=x/GCD(x,y);
		y=y/GCD(temp,y);
		long long chance=x*y;
		sum=sum+chance*4*temp1;
	} 
	printf("%lld",sum);
}