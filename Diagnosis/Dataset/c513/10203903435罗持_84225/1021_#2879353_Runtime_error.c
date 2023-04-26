#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char table[30];
int mycmp(const void* xx, const void* yy)
{
	char *x = (char*)xx;
	char *y = (char*)yy;
	char xxx[20],yyy[20];
	for(int i=0;i<strlen(x);i++) 
	{
		char c = x[i];
		if(c>'Z') c -= ('a'-'A');
		int idx = 0;
		for(int j=0;j<26;j++)
		{
			if(table[j]==c)
			{
				idx = j;
				break;
			}
		}
		xxx[i] = 'A'+idx;
	}
	xxx[strlen(x)] = '\0';
	for(int i=0;i<strlen(y);i++) 
	{
		char c = y[i];
		if(c>'Z') c -= ('a'-'A');
		int idx = 0;
		for(int j=0;j<26;j++)
		{
			if(table[j]==c)
			{
				idx = j;
				break;
			}
		}
		yyy[i] = 'A'+idx;
	}
	yyy[strlen(y)] = '\0';
	return strcmp(xxx,yyy);
}
int main(void)
{
	char s[111][20];
	while(~scanf("%s",table))
	{
		getchar();
		int len = 0;
		char a[30];
		int idx = 0;
		char c;
		while(scanf("%c",&c)!=EOF)
		{
			if(c=='\n')
			{
				a[idx] = '\0';
				len++;
				strcpy(s[len],a);
				break; 
			}
			else if(c==' ')
			{
				a[idx] = '\0';
				len++;
				strcpy(s[len],a);
				idx = 0;
			}
			else
			{
				a[idx] = c;
				idx++;
			}
		}
		qsort(s+1,len,sizeof(s[0]),mycmp);
		for(int i=1;i<=len;i++)
			printf("%s ",s[i]);
		putchar('\n');
	}	
	return 0;
}