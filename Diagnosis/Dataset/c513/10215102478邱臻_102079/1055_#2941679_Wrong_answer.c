#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i,j=0,flag=0,max=0,k,count=0,a;
	char c;
	char s[1000001];
	int number[10000]={},time[100]={};
	scanf("%s",s);flag=0;
	for(i=0;i<strlen(s);){
		if(time[s[i]-'0']==0){
			time[s[i]-'0']=i+1;  //记录下标
			count++;i++;
		}
		else if(time[s[i]-'0']!=0 || i==strlen(s)-1){
			max=max>count?max:count;  //记录最长子串
			number[count]=number[count]>flag?flag:number[count];   //记录初始位置 
			a=time[s[i]-'0'];time[s[i]-'0']=i+1;
			i=a-1;  //回到重复数字的下标
			flag=i;i++;
			count=0;
		}
	}
	max=max>count?max:count;
	for(k=0;k<max;k++){
		printf("%c",s[number[max]+k]);
	}
	return 0;
}