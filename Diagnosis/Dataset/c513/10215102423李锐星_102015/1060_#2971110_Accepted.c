#include <stdio.h>
#include <string.h>
#include <ctype.h>

void change(char* s,char* t)
{
	int i;
	for (i=0;i<strlen(s);i++){
		t[i]=s[i];
	}
	t[i]='\0'; 
}

int main()
{
	char s[101];
	scanf("%s",s);
	char num[101],result[101];
	num[0]='\0';
	result[0]='\0';
	int i;
	for (i=0;i<strlen(s);i++){
		int len=strlen(num);
		if(isdigit(s[i])){
			if(s[i]=='0'&&len==0);
			else{
				num[len]=s[i];
				num[len+1]='\0';
			}
		}
		else{
			if(strlen(num)>strlen(result)){
				change(num,result);
			}
			num[0]='\0';
		}
	}
	if(strlen(num)>strlen(result)){
		change(num,result);
	}
	printf("%d\n",strlen(result));
	return 0;
}