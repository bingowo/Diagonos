#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int t,i,j,count,k;
	char s[101];
	char c;
	scanf("%d",&t);
	getchar(); 
	for(i=0;i<t;i++){
		j=0;count=0;
		for(k=0;k<101;k++)s[k]='\0';
		while(c=getchar()){  //每一行的输入 
			if(c!=' ' && c!='\n'){
				s[j++]=c;  //c不是空格 属于同一个单词 
			}
			else if(strcmp(s,"anD") && strcmp(s,"An") && strcmp(s,"The") && strcmp(s,"For") && strcmp(s,"a") && strcmp(s,"the") && strcmp(s,"an") && strcmp(s,"of") && strcmp(s,"for") && strcmp(s,"and") && strcmp(s,"A") && strcmp(s,"THE") && strcmp(s,"AN") && strcmp(s,"OF") && strcmp(s,"FOR") && strcmp(s,"AND")){
				count++;
			}
			if(c==' '){
				for(k=0;k<j;k++){
					s[k]='\0';
				}
				j=0;
			}
			if(c=='\n')break;
		}
		printf("case #%d:\n%d\n",i,count);
	}
	
	return 0;
}