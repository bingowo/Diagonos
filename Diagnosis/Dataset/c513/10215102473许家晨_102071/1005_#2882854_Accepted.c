#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int T,cnt=0;
	scanf("%d",&T);
	while(T){
		char octal[55],decimal[155];
		scanf("%s",octal);
		int numbers=0;
		int len=strlen(octal)-1;
		int temp,digit;
		for(;len!=1;--len){
			digit=octal[len]-'0';
			int i=2;
			do{
				if(i<numbers){
					temp=digit*10+decimal[i]-'0';
				}
				else{
					temp=digit*10;
				}
				decimal[i++]=temp/8+'0';
				digit=temp%8;
			}while(digit || i<numbers);
			numbers=i;
		}
			decimal[numbers]='\0';
			decimal[0]='0';
			decimal[1]='.';
		printf("case #%d:\n%s\n",cnt,decimal);
	cnt++;
	T-=1;
	}
}