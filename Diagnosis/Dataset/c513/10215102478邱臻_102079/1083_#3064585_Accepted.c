#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long long int t,n,i,j,k,carry,max,result;
	long long int num[100000]={};
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		scanf("%lld",&n);
		for(j=0;j<100000;j++)num[j]=0;
		for(j=1;j<=n;j++){
			if(j==1){num[0]=1;max=1;}
			else {
				k=0;carry=0;
				while(k<=max || num[k]!=0){
					num[k]=num[k]*j+carry;
					carry=num[k]/10;num[k]=num[k]%10;  //进位计算 
				    k++;
				}
				if(carry)num[k]+=carry;  //最高位的进位计算
				if(num[k]==0)max=k-1;
				else max=k; 
			}
		}  //大整数相乘计算
		k=0;carry=0;
		for(k=0;k<=max;k++){
			num[k]+=carry;
			if(num[k]>=10){
				carry=num[k]/10;num[k]=num[k]%10;
			}
		}  //再次保证每一位小于十
		k=0;result=0;
		while(num[k]==0){result++;k++;}
		printf("case #%lld:\n%lld\n",i,result);
	}
	return 0;
}