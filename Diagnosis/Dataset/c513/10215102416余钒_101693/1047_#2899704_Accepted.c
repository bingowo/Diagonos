#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l;
char s[1005];
int main() {
	scanf("%d\n",&T);
	for(int c=0;c<T;c++){
		gets(s+1);
		printf("case #%d:\n",c);
		l=strlen(s+1);
		int cnt=0;
		for(int i=1;i<=l;i++){
			cnt++;
			if(cnt==255||s[i]!=s[i+1]) printf("%d%c",cnt,s[i]),cnt=0;
		}
		puts("");
	}
	return 0; 
}