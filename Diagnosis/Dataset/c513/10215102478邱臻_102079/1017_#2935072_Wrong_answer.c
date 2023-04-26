#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {  //1,5,10,50,100,500,1000
	char input[100000];
	long long int number[100000]={0};
    long long int i,flag=0,j=0,result=0;; 
	scanf("%s",input);   //输入字符串
	for(i=0;i<strlen(input);i++){
		if(input[i]=='('){
			if(flag==0)flag=1;  //扩大1000 
			else if(flag==1)flag=2;  //扩大1000000 
		}
		else if(input[i]==')'){
			if(flag==2)flag=1;   //扩大1000 
			else if(flag==1)flag=0;  //不扩大 
		}
		else{
			if(input[i]=='I'){
				if(flag==0)number[j]=1;
				else if(flag==1)number[j]=1*1000;
				else if(flag==2)number[j]=1*1000000;
			}
			else if(input[i]=='V'){
				if(flag==0)number[j]=5;
				else if(flag==1)number[j]=5*1000;
				else if(flag==2)number[j]=5*1000000;
			}
			else if(input[i]=='X'){
				if(flag==0)number[j]=10;
				else if(flag==1)number[j]=10*1000;
				else if(flag==2)number[j]=10*1000000;
			}
			else if(input[i]=='L'){
				if(flag==0)number[j]=50;
				else if(flag==1)number[j]=50*1000;
				else if(flag==2)number[j]=50*1000000;
			}
			else if(input[i]=='C'){
				if(flag==0)number[j]=100;
				else if(flag==1)number[j]=100*1000;
				else if(flag==2)number[j]=100*1000000;
			}
			else if(input[i]=='D'){
				if(flag==0)number[j]=500;
				else if(flag==1)number[j]=500*1000;
				else if(flag==2)number[j]=500*1000000;
			}
			else if(input[i]=='M'){
				if(flag==0)number[j]=1000;
				else if(flag==1)number[j]=1000*1000;
				else if(flag==2)number[j]=1000*1000000;
			}
			j++;
		}
	}   //将罗马数字化为阿拉伯数字并存入数组
	for(i=0;i<strlen(input)-1;i++){
		if(number[i]<number[i+1])result-=number[i];
		else result+=number[i];
	}
	printf("%lld",result+number[strlen(input)-1]);
	return 0;
}