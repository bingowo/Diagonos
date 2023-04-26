#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(char *result,int len){
	int i,j;
	char c;
	for(i=0,j=len-1;i<=j;i++,j--){
		c=result[i];result[i]=result[j];result[j]=c;
	}
}
int main() {
	int n,r,x,i=0,z;
	char result[100000];
	char alpha[36]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};   //进制字母表 
	scanf("%d %d",&n,&r);
	if(n==0)printf("0");
	else {
	while(n!=0){
		x=n%r;
		if(x<0){
			x=n-r*(n/r+1);n=n/r+1;
		}   //保证余数为正
		else n=n/r;
		result[i]=alpha[x];
		i++;
	}
	reverse(result,i);   //倒置字符串 
	for(z=0;z<i;z++)printf("%c",result[z]);
}
	return 0;
}