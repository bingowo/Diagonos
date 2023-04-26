#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	char num[2][32];
	int a[2];
	int n,t,j,k,l,i,x,result;
	scanf("%d",&t);  //问题组数 
	for(i=0;i<t;i++){
		for(j=0;j<2;j++){  //每组有两个数字 
			scanf("%d",&n);
			k=0;
			if(n==0)k=1;
			while(n!=0){
				l=n%2;n=n/2;
				num[j][k]=l+'0';
				k++;
			}  //将数字变为二进制字符串（倒序）
			a[j]=k;  //有用的共有K位 
		}
		if(a[0]<a[1])k=a[1];
		else k=a[0];
		result=0;
		for(x=0;x<k;x++){
			if(num[0][x]!=num[1][x])result++;
		}
		printf("%d\n",result);
	}
	return 0;
}