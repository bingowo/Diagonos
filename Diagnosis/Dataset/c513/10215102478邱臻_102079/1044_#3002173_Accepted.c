#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char s[100000],s1[100000]="0";
	int i=0,j,k,x,sign=0,flag=0,temp=0;
	unsigned int result;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(i>=1 && s[i]=='x' && s[i-1]=='0' && temp==0){
			sign=1;result=0;continue;  //对最终结果进行初始化 
		}
		if(sign){
			if(s[i]>='a' && s[i]<='f'){
				result=result*16+s[i]-'a'+10;temp=1;
			}
			else if(isdigit(s[i])){
			    result=result*16+s[i]-'0';temp=1;	
			}
			else {
				sign=0;  //结束计算
				if(temp){
					printf("%u ",result); 
					flag=1;result=0;temp=0;
				}
			}
		}
	}
	if(temp) printf("%u ",result);
	else if(flag==0) printf("-1");
	return 0;
}