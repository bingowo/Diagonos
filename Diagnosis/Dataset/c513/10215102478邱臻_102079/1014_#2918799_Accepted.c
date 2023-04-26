#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(char* number,int len){
	int i,j;
	char c;
	for(i=0,j=len-1;i<=j;i++,j--){
		c=number[i];number[i]=number[j];number[j]=c;
	}
}

int main() {
	long long int A,B;
	long long int i=0,z=0,x,y,a,b,j;
	char three[100000]={"0"};
	long long int result[100000];
	scanf("%lld %lld",&A,&B);
	if(A==0 || B==0)printf("0");
	else {
	a=A/B;b=A-(a*B);  //a为整数部分,b为小数部分 
	while(a!=0){
		x=a%3;a=a/3;
		three[i]=x+'0';
		i++;  //字符个数 
	}  //整数部分化为三进制 
	three[i]='0';i++;
	reverse(three,i); //倒置字符串 
	if(b!=0){
		three[i]='.';i++;
	}
	while(b!=0){
		b=b*3;
		y=b/B;b=b%B;
		three[i]=y+'0';
		i++;
	}   //小数部分化为三进制
	reverse(three,i);  //倒置字符串 
	for(j=0;j<i-1;j++){
		if(three[j]!='.'){
			three[j]+=1;
			if(three[j]>='3'){
				three[j]-=3;
				if(three[j+1]!='.')three[j+1]+=1;
				else three[j+2]+=1;
			}  //进位 
			result[j]=three[j]-'0'-1;
		}
		else result[j]=10;
	}   //与全1序相加相减 
	if(three[j]!='0'){
		result[j]=three[j]-'0';
		j++;
	}
	for(i=j-1;i>=0;i--){
		if(result[i]==10){
			if(i==j-1)printf("0");
			printf(".");
		} //输出小数点 
		else{
			if(result[i]==-1){
				result[i]=2;
			}
			printf("%lld",result[i]);
		}
	}}
	return 0;
}