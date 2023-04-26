#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char s[51];
	int len[51];
	int i,j,max=0,count;
	scanf("%s",s);  //输入字符串
	if(strlen(s)==1)max=1;
	else{
	for(i=0;i<strlen(s)-1;i++){
		j=i;count=1;
		while(s[j]!=s[j+1] && j+1<strlen(s)){
			count++;j++;
		}
		len[i]=count;
		max=max<len[i]?len[i]:max;  //记录最大值 
	} }
	printf("%d",max);
	return 0;
}