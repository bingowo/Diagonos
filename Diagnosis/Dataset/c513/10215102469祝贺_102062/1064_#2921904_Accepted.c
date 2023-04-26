#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	char c;
	int tag;
}sign;
sign stack[100];int sp=0;
double num[5];int nsp=0;
double ans=0;
void solve(char *s){
	int i=0;char* ptr;
	for(;i<strlen(s);i++){
		if(s[i]==' ' || s[i]=='\n');
		else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
			stack[sp].c=s[i];stack[sp].tag=0;sp++;
		}
		else if(isdigit(s[i])){
			num[nsp++]=strtod(s+i,&ptr);
			if(sp>0)stack[sp-1].tag++;
			while(s[i]!=' ' && s[i]!='\n')i++;
			i--;
		}
		if(stack[sp-1].tag==2){
			switch(stack[sp-1].c){
				case('+'):{
					num[nsp-2]=num[nsp-2]+num[nsp-1];
					break;
				}
				case('-'):{
					num[nsp-2]=num[nsp-2]-num[nsp-1];
					break;
				}
				case('*'):{
					num[nsp-2]=num[nsp-2]*num[nsp-1];
					break;
				}
				case('/'):{
					num[nsp-2]=num[nsp-2]/num[nsp-1];
					break;
				}
			}
			nsp--;sp--;
			if(sp>0)stack[sp-1].tag++;
		}
	}
	ans=num[0];
}
int main()
{
	int pro;scanf("%d",&pro);getchar();
	for(int index=0;index<pro;index++){
		char s[120];
		fgets(s,120,stdin);
		solve(s);
		printf("case #%d:\n%.6f\n",index,ans);
		ans=0;sp=0;nsp=0;
	}
	return 0;
}