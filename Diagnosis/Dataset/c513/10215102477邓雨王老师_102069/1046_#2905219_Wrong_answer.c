#include<stdio.h>
#include<string.h>
int count=0;
int cmp(char s[]){
	if(strcmp(s,"a")==0||strcmp(s,"an")==0||strcmp(s,"the")==0||strcmp(s,"for")==0||strcmp(s,"of")==0||strcmp(s,"and")==0) return 0;
	else return 1;
}
int main(){
	int chance;
	scanf("%d\n",&chance);
	int i;
	for(i=0;i<chance;i++){
		char s[101];
		char c[100][20];
		gets(s);
		int j;
		int t=0,p=0;
		for(j=0;j<strlen(s);j++){
			if(s[j]!=' '){
				c[t][p]=s[j];
				p++;
			}
			else{
				c[t][p]='\0';
				t++;
				p=0;
			}
		}
		c[t][p]='\0';
		for(j=0;j<=t;j++){
			if(cmp(c[j])==1) count++;
		}
		printf("case #%d:\n",i);
		printf("%d\n",count);
	}	
}