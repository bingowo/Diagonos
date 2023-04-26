#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alpha[100];
struct string
{
	char str[100];	
};

int cmp(const void*a,const void*b)
{
	struct string *c=(struct string *)a;
	struct string *d=(struct string *)b;
	char ch1,ch2;
	int len1,len2,i=0;
	len1=strlen(c->str);
	len2=strlen(d->str);
	while(c->str[i] && d->str[i])
	{
		ch1 = c->str[i]>='a' ? c->str[i]-32:c->str[i];
		ch2 = d->str[i]>='a' ? d->str[i]-32:d->str[i];
		if(alpha[ch1-'A'] != alpha[ch2-'A'])
			return alpha[ch1-'A']-alpha[ch2-'A'];
		else
			i++;
	}
	if(c->str[i] == 0)
		return -1;
	else return 1;
}
int main()
{
	char c;
	c=getchar();
	int i=0;
	while(c!='\n')
	{
		alpha[c-'A']=i++;
		c=getchar();
	}
	i=0;
	int j=0;
	struct string S[100];
	c=getchar();
	while(c!='\n')
	{
		if(c!=' ')
		{
			S[j].str[i] = c;
			i++;
		}
		else
		{
			S[j].str[i]='\0';
			i=0;
			j++;
		}
		c=getchar();
	}
	
	qsort(S,j+1,sizeof(S[0]),cmp);
	
	for(i=0;i<j;i++)
	{
		printf("%s ",S[i].str);
	}
	printf("%s\n",S[i].str);
	return 0;
}