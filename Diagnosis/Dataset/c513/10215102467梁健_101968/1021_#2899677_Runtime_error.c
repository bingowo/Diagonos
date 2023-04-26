#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int alphabet[26];
//alphabet 0-25 A-Z  [c]1-26 sort

int cmp(const void *a,const void *b)
{
	char *a1=*(char *)a;
	char *b1=*(char *)b;
	char a2=*a1;
	char b2=*b1;
	a2=toupper(a2);
	b2=toupper(b2);
	return alphabet[a2-'A']-alphabet[b2-'A'];
}

int main()
{
	char sort[27];
	while(scanf("%s",sort)!=EOF)
	{
		int i;
		for(i=0;i<26;i++)
		{
			alphabet[sort[i]-'A']=i+1;
		}//顺序
		char a[101][21];
		char c;
		i=0;
		do
		{
			scanf("%s",a[i]);
			i++;
 		}while(c=getchar()==' ');
 		qsort(a,i,sizeof(char *),cmp);
 		int j=0;
 		for(;j<i-1;j++)
 		{
 			printf("%s ",a[j]);
		 }
		 printf("%s\n",a[i-1]);
	}
	return 0;
}
