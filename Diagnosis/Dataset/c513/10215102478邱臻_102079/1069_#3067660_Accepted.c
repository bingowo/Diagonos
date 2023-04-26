#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int count=0;
long long int huiwen(long long int n){
	long long int N=n,m,flag=0,i=0,j,k;
	long long c[1000]={};
	while(N>0){
		c[i++]=N%10;N=N/10;
	}  //将数字放入数组
	for(j=0,k=i-1;j<=k;j++,k--){
		if(c[j]!=c[k])flag=1;
	} 
	if(flag==0)return n;
	else {
		count++;m=0;
		for(j=0;j<i;j++){
			m=m*10+c[j];
		}
		return huiwen(n+m);
	}
}
int main(int argc, char *argv[]) {
	long long int n;
	scanf("%lld",&n);
	printf("%d %lld",count,huiwen(n));
	return 0;
}