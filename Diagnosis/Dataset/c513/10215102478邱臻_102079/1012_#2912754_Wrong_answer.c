#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long a=0,b=0,qr,qi,r;
    char input[100000],result[100000];
    int i=0,flag=1,k,j;
    scanf("%s",input);
    if(strchr(input,'i')==NULL){
    	b=0;  //没有虚数部分
		for(i=0;i<strlen(input);i++){
			if(input[i]=='-')flag=-1;
			else{
				a+=a*10+input[i]-'0';
			}
		}
		if(flag==-1)a=-a;   //实数部分计算 
	}
	else if(strchr(input,'+')==NULL && strchr(input,'-')==strrchr(input,'-') && strchr(input,'i')!=NULL) {
        a=0;  //没有实数部分
        if(input[0]=='i')b=1;
        else {
        	if(input[0]=='-'){
        		flag=-1;i++;
			}
			if(input[i]=='i')b=-1;  //只有-i 
			else{
				while(input[i]!='i'){
			    	b+=b*10+input[i]-'0';
			    	i++;
				}
				if(flag==-1)b=-b;  //虚数部分计算
			}
		}		
	}
	else {
		if(input[0]=='-'){
			flag=-1;i++;
		}
		while(input[i]!='+' && input[i]!='-'){
			a+=a*10+input[i]-'0';
			i++;   //实数部分 
		}
		if(flag==-1)a=-a;
		flag=1;
		if(input[i+1]=='i'  && input[i]=='+')b=1;
        else {
        	if(input[i]=='-'){
        		flag=-1;i++;
			}
			i++;
			if(input[i]=='i')b=-1;  //只有-i 
			else{
				while(input[i]!='i'){
			    	b+=b*10+input[i]-'0';
			    	i++;
				}
				if(flag==-1)b=-b;  //虚数部分计算
			}
		}
	}
	j=0;
	do{
		if(a%2!=0 && b%2==0 || a%2==0 && b%2!=0){  //不同时为奇偶数 
			r=1;
		}
		else r=0;
		qi=(a+b-r)/(-2);
		qr=b+qi;
		a=qr;b=qi;
		result[j++]=r+'0';
	}while(a!=0 || b!=0);
	for(k=j-1;k>=0;k--)printf("%c",result[k]);
	return 0;
}