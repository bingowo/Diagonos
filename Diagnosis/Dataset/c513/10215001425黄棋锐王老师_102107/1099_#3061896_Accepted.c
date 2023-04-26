#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000000007

const char*moose[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",
"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};//'A'~'Z','0'~'9'



int main() 
{ int t,T;
	scanf("%d\n",&T);
  for(t=0;t<T;t++)
  {
  	char s[1002]={'\0'};
	char text[1000]={'\0'};
	gets(s);
	printf("case #%d:\n",t);
	int i=0,l=strlen(s),n=0;
	while(i<l)
 {	char c;
	char code[7]={'\0'};
	int j=0,k=0;
	while(s[i]=='-'||s[i]=='.') code[j++]=s[i++]; 
	for(k=0;k<36;k++)//处理一个字母 
	{
		if(strcmp(code,moose[k])==0)
		{ 
			if(k<26) c='A'+k;
			else c='0'+k-26;
			text[n++]=c;
		 	break;//找到才break; 
		 }
	}
	
	if(k>=36) printf("Data Error!\n");
	
	int flag=0;
	while(s[i]=='/') flag++,i++;
	if(flag==3) text[n++]=' ';
	else if(flag==5) text[n++]='.';
 }
 	printf("%s\n",text);
  }
		
	return 0;
}