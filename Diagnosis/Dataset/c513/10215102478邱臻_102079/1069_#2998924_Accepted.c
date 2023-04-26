#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int count=0;
long long int put(long long int N){
	long long int c[100],i=0,j,flag,n=N,q=0;
	while(n>0){
		c[i++]=n%10;n=n/10;
	}  //记录数字
	for(j=0,flag=0;j<i;j++){
		if(c[j]!=c[i-j-1])flag=1;
	} 
	if(flag==0)return N;
	count++;
	for(j=0;j<i;j++){
		q=q*10+c[j];
	}  //数字形式
	return put(N+q); 
	
}
int main(){
	long long int n;
	scanf("%lld",&n);
	printf("%d %lld",count,put(n));
	return 0;
}
