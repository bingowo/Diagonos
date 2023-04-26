#include <stdio.h>
#include <string.h>
int main()
{
	char s[1001];
	char c;
	c=getchar();
	if(c>='a'&&c<='z') c-=32;
	s[0]=c;
	while((c=getchar())!='\n')
	{
		if(c>='a'&&c<='z') c-=32;
		char s2[2]={'0'};
		s2[0]=c;
		s2[1]='\0';
		if(s[0]>c) strcat(s,s2);
		else{
			strcat(s2,s);
			strcpy(s,s2);
		}
	}
	printf("%s\n",s);
	return 0;
}