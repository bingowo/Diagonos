#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	char num[32];
	int n,t,j,k;
	scanf("%d",&t);  //问题数 
	for(i=0;i<t;i++){
		scanf("%d",&n);
		k=0;j=0;
		while(n!=0){
			j=n%2;n=n/2;
			num[k]=j+'0';
			k++;
		}   //将数字变为二进制字符串（倒序）
		
	}
	return 0;
}