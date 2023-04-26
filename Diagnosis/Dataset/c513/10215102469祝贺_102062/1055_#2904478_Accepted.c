#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[1000500];
int main(){
	scanf("%s",s);
	long long len=strlen(s),p1=0,p2=0,left=0,right=0;
	for(;p2<len;p2++){
		for(int i=p1;i<p2;i++){
			if(s[i]==s[p2]){
				p1=i+1;break;
			}
		}
		if(right-left+1<p2-p1+1){
			right=p2;left=p1;
		}
	}
	for(int i=left;i<=right;i++)printf("%c",s[i]);
	
	return 0;
}