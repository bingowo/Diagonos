#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char up(char a){
	if(a>='a'&&a<='z')
		a=a-'a'+'A';
	return a;
}
int main()
{
	char word[1002];
	scanf("%s",word);
	char r[1002]={'\0'};
	for(int i=0;i<strlen(word);i++){
		word[i]=up(word[i]);
		char s1[1002]={'\0'},s2[1002]={'\0'};
		s1[0]=s2[0]=up(word[i]);
		strcat(s1,r);
		strcat(r,s2);
		if(strcmp(s1,r)>0)
			strcpy(r,s1);			
	}
	printf("%s",r);
	return 0;
}