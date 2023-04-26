#include <stdio.h>
#include <string.h>

char s[1000001];
char t[1000001];
char result[1000001];

void trans(char *s,char c,int pos)
{
	int len=strlen(s);
	int i;
	if(s[len-1]==c){
		s[0]=c;
		s[1]='\0';
	}
	else{
		for (i=0;i<len-pos-1;i++){
			t[i]=t[i+pos+1];
		}
	}
	t[i]=c;
	t[i+1]='\0';
}


int main()
{
	scanf("%s",s);
	t[0]='\0';
	result[0]='\0';
	int i;
	char* pos;
	for (i=0;i<strlen(s);i++){
		pos=strrchr(t,s[i]);
		int len=strlen(t);
		if(pos==NULL){
			t[len]=s[i];
			t[len+1]='\0';
		}
		else{
			if(strlen(t)>strlen(result)){
				strcpy(result,t);
			}
			trans(t,s[i],pos-t);
		}
	}
	if(strlen(t)>strlen(result)){
		strcpy(result,t);
	}
	printf("%s\n",result);
	return 0;
}