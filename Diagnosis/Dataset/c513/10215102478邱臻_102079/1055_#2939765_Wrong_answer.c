#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i,j=0,flag=0,max=0,k;
	char c;
	char s[100000];
	int number[10000]={},time[100]={};
	while(1){
		c=getchar();
		if(!time[c-'0']){  //字符没有出现过
		    time[c-'0']++;
			s[j++]=c; 
		}  //记录子串
		else if(time[c-'0'] || c=='\n'){
			max=max>j-flag?max:j-flag;  //最长子串 
			number[j-flag]=flag;  //起始位置 
			flag=j;
			for(k=0;k<100;k++)time[k]=0;
			time[c-'0']++;s[j++]=c;
		} 
		if(c=='\n')break;
	}
	for(j=0;j<max;j++){
		printf("%c",s[number[max]+j]);
	}
	return 0;
}