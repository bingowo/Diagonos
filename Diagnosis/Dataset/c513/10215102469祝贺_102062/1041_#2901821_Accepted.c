#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char s[55];
int main(){
	scanf("%s",s);
	int begin=0,end=1,ans=1;
	int len=strlen(s);
	int temp=1;
	for(end=begin+1;end<len;end++){
		if(s[end]!=s[end-1])temp++;
		else {
			ans=temp>ans?temp:ans;
			begin=end;temp=1;
		}
	}
	ans=temp>ans?temp:ans;
	printf("%d",ans);
} 
