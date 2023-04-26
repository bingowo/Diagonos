#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char s[100000],s1[100000]="0";
	int i=0,j,k,x,sign=0,flag=0;
	unsigned int result;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(i>=2 && s[i-1]=='x' && s[i-2]=='0'){
			sign=1;flag=1;
			for(j=0;j<k;j++)s1[j]='0';
			k=0;result=0;
		}
		if(sign){  //记录数字 
			if(s[i]>='a' && s[i]<='f')x=s[i]-'a'+10;
			else if(isdigit(s[i]))x=s[i]-'0';
			else {
				sign=0;flag=2;
				printf("%u ",result);
				continue;
			}
			result=result*16+x;
		}
		if(s[i+1]=='0' && s[i+2]=='x' && i+1<=strlen(s)-2){
			sign=0;flag=2;
			printf("%u ",result);
		}
	}
	if(flag==1)printf("%u",result);
	else if(flag==0)printf("-1");
	return 0;
}