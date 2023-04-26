#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int T;
char s[1005];
int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%s",s);
		int ans=0;
		for(int i=0;s[i]!='\0';i++){
			if(s[i]=='-') ans=ans*3-1;
			else ans=ans*3+s[i]-'0';
		}
		printf("case #%d:\n%d\n",c,ans);
	}
	return 0; 
} 