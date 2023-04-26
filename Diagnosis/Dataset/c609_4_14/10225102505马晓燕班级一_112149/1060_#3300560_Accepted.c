#include <stdio.h>
#include <string.h>

void insert(char *s,int pos)//双倍复制pos位置的字母
{
	int i;
	for(i=strlen(s)+1;i>pos;i--)
		s[i]=s[i-1];
}

int main()
{
	char s[201],t[201];
	int len;
	scanf("%s",s),len=strlen(s);
	for(int i=0;i<len;i++)
	{
		strcpy(t,s);
		insert(t,i);
		if(strcmp(t,s)<0)
			len++,i++,strcpy(s,t);
	}
	printf("%s\n",s);
	return 0;
}