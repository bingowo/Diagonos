#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char *moose[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
	int n,m;
	scanf("%d",&n);
	getchar();
	for(m=0;m<n;m++){
		printf("case #%d:\n",m);
		char s[1001],code[6],text[501],ch;
		gets(s);
		int i=0,k,n1=0,flag=0;
		while(s[i]){
			int j=0;
			while(s[i]=='.'||s[i]=='-') code[j++]=s[i++];
			code[j]='\0';
			for(k=0;k<36;k++)
				if(strcmp(code,moose[k])==0){
					if(k<26) ch=k+65;
					else ch=k+22;
					text[n1++]=ch;break;}
				if(k>=36) {printf("Data Error!\n");return;
			}
			flag=0;
			while(s[i]=='/'){flag++;i++;}
			if(flag==3) text[n1++]=' ';
			if(flag==5) text[n1++]='.';
		}text[n1]='\0';printf("%s\n",text);
		
	}
	return 0;
}