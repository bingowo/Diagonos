#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a,const void *b)
{
	char a1=*(*(char *)a);
	char b1=*(*(char *)b);
	a1=toupper(a1);
	b1=toupper(b1);
	return alphabet[a1-'A']-alphabet[b1-'A'];
}
char alphabet[26];
//alphabet 0-25 A-Z  [c]1-26 sort
int main()
{
	char sort[26];
	scanf("%s",sort);
	int i;
	for(i=0;i<26;i++)
	{
		alphabet[sort[i]-'A']=i+1;
	}//顺序
	char *a[101];
	char c;
	i=0;
	do{
		do
		{
			scanf("%s",a[i]);
			i++;
	 	}while ((c=getchar())==' ');
	 	qsort(a,i,sizeof(char *),cmp);
	}while(c!=EOF)
	
	for(;i--;i>0)
	{
		printf("%s",a[i]);
	}
	return 0;
}
