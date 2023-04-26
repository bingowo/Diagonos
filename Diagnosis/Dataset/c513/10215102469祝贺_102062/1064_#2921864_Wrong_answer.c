#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char stack[100];int sp=0;
double num[5];int nsp=0;
double ans=0;
void solve(char *s){
	int i=0;char* ptr;
	for(;i<strlen(s);i++){
		if(s[i]==' ' || s[i]=='\n');
		else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
			stack[sp++]=s[i];
		}
		else if(isdigit(s[i])){
			num[nsp++]=strtod(s+i,&ptr);
			while(s[i]!=' ' && s[i]!='\n')i++;
		}
		if(nsp==2){
			nsp=0;
			switch(stack[sp-1]){
				case('+'):{
					num[0]=num[0]+num[1];
					break;
				}
				case('-'):{
					num[0]=num[0]-num[1];
					break;
				}
				case('*'):{
					num[0]=num[0]*num[1];
					break;
				}
				case('/'):{
					num[0]=num[0]/num[1];
					break;
				}
			}
			nsp=1;sp--;
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