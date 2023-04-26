#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int gcd(int a,int b){
	int m,n;
	m=a>b?a:b;n=a<b?a:b;
	if(n==0)return m;
	else return gcd(n,m%n);
}
int main(int argc, char *argv[]) {
	char n[501];
	char str[10];
	int number,i,j,k,a,len; 
	scanf("%s",n);  //非负字符串的输入
	printf("0001");  //输出数字编码
	for(i=0;i<10;i++)str[i]='0';
	len=strlen(n);i=0;
	while(len!=0){
		a=len%2;len=len/2;
		str[i++]=a+'0';
	}
	for(i=9;i>=0;i--)printf("%c",str[i]);  //输出数字的个数
	for(i=0;i<strlen(n);i+=3){
		if(strlen(n)-i<3)break;  //剩余数字不够三个 
		else{
			for(j=0;j<10;j++)str[j]='0';
			for(j=0;j<3;j++){
				number=number*10+n[i+j]-'0';
			}  //化为整数
			j=0;
			while(number!=0){
				a=number%2;number=number/2;
				str[j++]=a+'0';
			}   //化为字符串 
			for(j=9;j>=0;j--)printf("%c",str[j]);
		}
	}
	if(strlen(n)-i==2){
		for(j=0;j<10;j++)str[j]='0';
		for(j=0;j<2;j++){
			number=number*10+n[i+j]-'0';
		}  //化为整数
		j=0;
		while(number!=0){
			a=number%2;number=number/2;
			str[j++]=a+'0';
		}   //化为字符串 
		for(j=6;j>=0;j--)printf("%c",str[j]);
	} 
	else if(strlen(n)-i==1){
		for(j=0;j<10;j++)str[j]='0';
		for(j=0;j<1;j++){
			number=number*10+n[i+j]-'0';
		}  //化为整数
		j=0;
		while(number!=0){
			a=number%2;number=number/2;
			str[j++]=a+'0';
		}   //化为字符串 
		for(j=4;j>=0;j--)printf("%c",str[j]);
	}
	return 0;
}