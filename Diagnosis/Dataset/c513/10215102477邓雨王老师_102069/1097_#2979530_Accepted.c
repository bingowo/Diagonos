#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	int i,j;
	while(scanf("%s",&s)!=EOF){
		char c[160][160];
		for(i=0;i<160;i++){
			for(j=0;j<159;j++){
				c[i][j]=' ';
			}
		}
		c[80][0]=s[0];
		int line=80,row=0,min=80,max=80; //line表示行，row表示列 
		for(i=1;i<strlen(s);i++){
			if(s[i]>s[i-1]) {c[++line][++row]=s[i];if(max<line) max=line;}
			else if(s[i]==s[i-1]) {c[line][++row]=s[i];}
			else {c[--line][++row]=s[i];if(min>line) min=line;}
		}
		for(j=max;j>=min;j--){
			printf("%s\n",c[j]);
		}
	}
}