#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],a[1000];	
	while(gets(a)!=NULL){
		a[strlen(a)]='\n';
		strcat(s,a);
	}
	int type=0;
	for(int i=0;i<strlen(s);i++){
		if(type==0&&s[i]=='\"'&&s[i-1]!='\\'){
			type=5;
			printf("%c",s[i]);
			continue; 
		}
		if(type==5){
			if(s[i]=='\"'&&(s[i-1]!='\\'||(s[i-1]=='\\'&&s[i-2]=='\\')))
				type=0;
		}
		if(type==0&&s[i]=='\''&&s[i-1]!='\\'){
			type=6;
			printf("%c",s[i]);
			continue; 
		}
		if(type==6){
			if(s[i]=='\''&&(s[i-1]!='\\'||(s[i-1]=='\\'&&s[i-2]=='\\')))
				type=0;
		}
		if(type==0&&s[i]=='/'){
			type=1;continue;
		}
		if(type==1){
			if(s[i]=='/')
				type=4;
			else if(s[i]=='*')
				type=2;
			else{
				printf("/%c",s[i]);
				type=0;
			}				
			continue;
		}
		if(type==4&&s[i]=='\n'){
			printf("\n");
			type=0;continue;
		}
		if(type==2&&s[i]=='*'){
			type=3;continue;
		}
		if(type==3){
			if(s[i]=='*')
				type=3;
			else if(s[i]=='/')
				type=0;
			else
				type=2;
			continue;
		}
		if(type==0||type==5||type==6){
			printf("%c",s[i]);
		}			
	}
	return 0;
}