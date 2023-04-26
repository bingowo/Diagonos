#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[20000],ans[20000];
int ssp=0,asp=0;
char stack[10000];int sp=0;
int main(){
	char c;
	while((c=getchar())!=EOF){
		s[ssp++]=c;
	}
	int i=0;
	while(i<ssp){
		switch(s[i]){
			case('"'):{
				if(sp==0){
					stack[sp++]=s[i];
					ans[asp++]=s[i];
				}
				else{
					if(stack[sp-1]=='\\'){
						sp--;ans[asp++]='\\';ans[asp++]='"'; 
					}
					else if(stack[sp-1]=='"'){
						sp--;ans[asp++]='"';
					}
				}
				i++;
				break;
			}
			case('\''):{
				if(sp==0){
					stack[sp++]=s[i];
					ans[asp++]=s[i];
				}
				else{
					if(stack[sp-1]=='\\'){
						sp--;ans[asp++]='\\';ans[asp++]='\''; 
					}
					else if(stack[sp-1]=='\''){
						sp--;ans[asp++]='\'';
					}
				}
				i++;
				break;
			}
			case('\\'):{
				if(sp==0){
					printf("error\n");
				}
				else{
					if(stack[sp-1]=='\\'){
						sp--;ans[asp++]='\\';ans[asp++]='\\'; 
					}
					else stack[sp++]='\\';
				}
				i++;
				break;
			}
			case('/'):{
				if(sp==0){
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
				}
				else{
					if(stack[sp-1]=='\\'){
						sp--;ans[asp++]='\\';ans[asp++]='/'; 
					}
					else ans[asp++]='/';
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