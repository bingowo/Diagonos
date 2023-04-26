#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long long int t,n,i,j,k,carry,max,a;
	long long int num[100000]={};
	scanf("%lld",&n);
	while(n!=0){
		for(j=0;j<100000;j++)num[j]=0;
		num[0]=1;max=1;
		for(j=0;j<n;j++){
			k=0;carry=0;
			while(num[k]!=0 || k<max){
				num[k]=num[k]*n+carry;
				carry=num[k]/10;num[k]=num[k]%10;  //进位运算 
			    k++;
			}  //每一位与a相乘
			if(carry){
				num[k]+=carry;
				while(num[k]>=10){
					carry=num[k]/10;num[k]=num[k]%10;
					k++;
					num[k]+=carry;
				}
		    }
			if(num[k]==0)max=k;
			else max=k+1;
		}  //幂运算
		k=0;carry=0;
		for(k=0;k<max;k++){
			num[k]+=carry;
			if(num[k]>=10){
				carry=num[k]/10;num[k]=num[k]%10;
			}
		}  //再次保证每一位小于十
		if(carry){
			num[k]+=carry;
			while(num[k]>=10){
				carry=num[k]/10;num[k]=num[k]%10;
				k++;
				num[k]+=carry;
			}
		}
		printf("%lld\n",num[k-1]);
		scanf("%lld",&n);
	}
	return 0;
}