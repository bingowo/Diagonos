#include <stdio.h>
#include <string.h>

char s[1000001];
char t[1000001];
char result[1000001];
int cmp(char c,char* t)
{
	int i;
	for (i=0;i<strlen(t);i++){
		if(c==t[i]){
			return 0;
		}
	}
	return 1;
}

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
	scanf("%s",s);
	t[0]='\0';
	result[0]='\0';
	int i;
	int flag;
	for (i=0;i<strlen(s);i++){
		flag=cmp(s[i],t);
		int len=strlen(t);
		if(flag){
			t[len]=s[i];
			t[len+1]='\0';
		}
		else{
			if(strlen(t)>strlen(result)){
				change(t,result);
			}
			t[0]=s[i];
			t[1]='\0';
			
		}
	}
	if(strlen(t)>strlen(result)){
		change(t,result);
	}
	printf("%s\n",result);
	return 0;
}