#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,l;
char s[1005];
int main() {
	scanf("%s",s+1);
	l=strlen(s+1);
	int hav=0,flg=0;
	long long res=0;
	for(int i=1;i<=l;i++){
		if(s[i]=='0'){
			if(i<l&&s[i+1]=='x'){
				if(flg) printf("%lld ",res),res=0,hav=1;
				flg=1;
				i++;
			}
			else {
				if(flg) res=res*16+s[i]-'0';
			}
		}else if(s[i]>='1'&&s[i]<='9'||s[i]>='a'&&s[i]<='f'){
			if(flg){
				if(s[i]>='1'&&s[i]<='9')res=res*16+s[i]-'0';
				else res=res*16+s[i]-'a'+10;
			} 
		}else{
			if(flg) printf("%lld ",res),res=0,hav=1,flg=0;
		}
	}if(flg)
		printf("%lld ",res),hav=1;
	if(!hav) puts("-1");
	return 0; 
}