#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int t,i,j,k,a,n;
	int length[]={1,1}; 
	char num[1000];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		j=0;
		while(n!=0){
			a=n%2;n=n/2;
			num[j++]=a+'0';  //二进制字符串 
		}
		length[0]=0;length[1]=1;
		for(k=1;k<j;k++){
			if(num[k]==num[k-1])length[0]=1;  //不符合非重复条件
			else length[0]++;  //开始计数
			length[1]=length[0]>length[1]?length[0]:length[1];  //保存最大值 
		}
		printf("case #%d:\n%d\n",i,length[1]);
	}
	return 0;
}