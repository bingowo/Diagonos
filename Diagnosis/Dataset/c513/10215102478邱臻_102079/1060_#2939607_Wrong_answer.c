#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int number[101]={};
	int flag=0,max=0,count=0,i;
	char s[101];
	scanf("%s",s);  //输入字符串
	for(i=0;i<strlen(s);i++){
		if(isdigit(s[i])){  //前一个字符也是数字
		    if(s[i]!='0' && flag)count++;
		    else if(s[i]!='0' && flag==0){
		    	flag=1;
		    	count++;
			}
		}
		else{
			max=max<count?count:max;
			count=0;  //计数清零 
			flag=0;
		}
	}
	printf("%d",max);
	return 0;
}