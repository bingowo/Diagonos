#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long int t,i,j,result,n;
	long long int number[100000];
	number[0]=0;number[1]=1;number[2]=1;
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		scanf("%lld",&n);  //n开始递归
		for(j=3;j<=n;j++){
			if(n==0 || n==1 || n==2)break;
			else {
				number[j]=number[j-1]+number[j-2]+number[j-3];
			}
		}
		printf("case #%lld:\n%lld\n",i,number[n]);
		for(j=3;j<=n;j++)number[j]=0;
	}
	return 0;
}