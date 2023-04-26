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
			return i;
		}
	}
	return -1;
}

void change(char* s,char* t)
{
	int i;
	for (i=0;i<strlen(s);i++){
		t[i]=s[i];
	}
	t[i]='\0'; 
}

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
	int pos;
	for (i=0;i<strlen(s);i++){
		pos=cmp(s[i],t);
		int len=strlen(t);
		if(pos==-1){
			t[len]=s[i];
			t[len+1]='\0';
		}
		else{
			if(strlen(t)>strlen(result)){
				change(t,result);
			}
			trans(t,s[i],pos);
		}
	}
	if(strlen(t)>strlen(result)){
		change(t,result);
	}
	printf("%s\n",result);
	return 0;
}