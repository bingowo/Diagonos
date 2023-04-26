#include <stdio.h>
#include <string.h>

int main()
{
	char s[1001];
	scanf("%s",s);
	int i=0,len;
	len=strlen(s);
	for(i;i<len;i++)
	{
		if(s[i]>='a'&&s[i]<='z') s[i]=s[i]-32;
	}
	char s1[100];
	s1[0]=s[0];
	int j=1;
	for(j;j<len;j++)
	{
		char s2[2]={'0'};
		s2[0]=s[j];
		s2[1]='\0';
		
		if(s1[0]>s2[0]) strcat(s1,s2);
		else 
		{
			strcat(s2,s1);
			strcpy(s1,s2);
		}
		
	}
	printf("%s",s1);
	return 0;
}