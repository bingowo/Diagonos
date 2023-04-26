#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l;
char S[10005];
int main() {
	while(~scanf("%s",S)){
		if(S[0]=='E') break;
		l=strlen(S);
		int h,m,s,loc=0;
		for(int i=0;i<l;i++){
			if(S[i]==','){
				h=(S[i+1]-'0')*10+S[i+2]-'0';
				m=(S[i+3]-'0')*10+S[i+4]-'0';
				s=(S[i+5]-'0')*10+S[i+6]-'0';
				h=(h+8)%24;
				if(S[i+12]=='A') loc=1;
				break;
			}
		}
		int sm=0,xsum;
		sscanf(S+l-2,"%x",&xsum);
		for(int i=1;i<l-3;i++) sm^=S[i];
		if(loc&&sm==xsum) printf("%02d:%02d:%02d\n",h,m,s);
	}
	return 0;
}