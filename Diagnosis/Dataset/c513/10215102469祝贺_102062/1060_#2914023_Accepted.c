#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int ans=0;
int f(char* s){
	int len=0;
	while(s[len]<='9' && s[len]>='0')len++;
	ans=ans>len?ans:len;
	return len;
}
int main(){
	char s[200];scanf("%s",s);
	int i=0;
	while(i<strlen(s)){
		if(!(s[i]<='9' && s[i]>'0'))i++;
		else{
			i=i+f(s+i);
		}
	}
	printf("%d",ans);
}