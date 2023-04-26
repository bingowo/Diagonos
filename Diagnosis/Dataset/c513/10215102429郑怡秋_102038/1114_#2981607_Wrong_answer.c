#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void cor(char ind[],int a[])
{
	int l=strlen(ind);
	int i=0;
	int sign=1;
	if(ind[i]=='-') sign=-1;
	while(i<=l)
	{
		int an=0;
		while(isdigit(ind[i]))
		{
			an=an*10+ind[i++]-'0';
		}
		if(isalpha(ind[i]))
		{
			if(an==0) an=1;
			if(ind[i+1]=='^') a[ind[i+2]-'0']=an*sign;
			else a[1]=an*sign;
		}
		if(ind[i]=='-')
		{
			sign=-1;
		}
		else if(ind[i]=='+')
		{
			sign=1;
		}
		if(i==l&&isdigit(ind[i-1])&&(ind[i-2]!='^'||ind[i-2]!='^'))
		{
			a[0]=an*sign;
		}
		i++;
	}

}
int main()
{
	char s[20];
	scanf("%s",s);
	int a[10];
	cor(s,a);
	if(a[1]==0) printf("No Answer!\n");
	return 0;
}