#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[20000],ans[20000];
int ssp=0,asp=0;
int main(){
	char c;
	while((c=getchar())!=EOF){
		s[ssp++]=c;
	}
	int i=0;
	while(i<ssp){
		switch(s[i]){
			case('"'):{
				int temp=strchr(s+i+1,'"')-s;
				while(s[temp-1]=='\\') temp=strchr(s+temp+1,'"')-s;
				strncpy(ans+asp,s+i,temp-i+1);
				asp+=temp-i+1;i=temp+1;
				break;
			}
			case('\''):{
				int temp=strchr(s+i+1,'\'')-s;
				while(s[temp-1]=='\\') temp=strchr(s+temp+1,'\'')-s;
				strncpy(ans+asp,s+i,temp-i+1);
				asp+=temp-i+1;i=temp+1;
				break;
			}
			case('/'):{
				if(s[i+1]=='/'){
					int temp=strchr(s+i+1,'\n')-s;i=temp;
				}
				else if(s[i+1]=='*'){
					int temp=strchr(s+i+2,'*')-s;
					while(s[temp+1]!='/'){
						temp=strchr(s+temp+1,'*')-s;
					}
					i=temp+2;
				}
				else{
					ans[asp++]=s[i];
					i++;
				}
				break;
			}
			default:{
				ans[asp++]=s[i];
				i++;
				break;
			}
		}
	}
	for(int j=0;j<asp;j++)printf("%c",ans[j]);
	return 0;
}