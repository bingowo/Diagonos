#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char s[51];
	long long int flag=1,result=0,i,j,z;
	long long int Roma[128]={};Roma['I']=1;Roma['V']=5;Roma['X']=10;Roma['L']=50;Roma['C']=100;Roma['D']=500;Roma['M']=1000;
	long long int num[100];
	scanf("%s",s);
	for(i=0,z=0;i<strlen(s);i++){
		switch(s[i]){
			case '(':
				flag*=1000;break;
		    case ')':
			    flag/=1000;break;
			default :
			    num[z++]=Roma[s[i]]*flag;break;		
		}
	}  //转化为阿拉伯数字
	for(i=0;i<strlen(s)-1;i++){
		if(num[i]<num[i+1])result-=num[i];
		else result+=num[i];
	}
	result+=num[i];
	printf("%lld",result);
	return 0;
}