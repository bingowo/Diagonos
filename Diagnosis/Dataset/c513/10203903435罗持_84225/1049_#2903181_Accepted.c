#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int T;
int mycmp(const void *aa,const void *bb)
{
	char *a = (char*)aa;
	char *b = (char*)bb;
	return strcmp(a,b);
}
int main(void)
{
	scanf("%d",&T);
	getchar();
	for(int kase=0;kase<T;kase++)
	{
		char s[600];
		char t[500][500] = {0};
		gets(s);
		int len = strlen(s);
		int pos = 0;
		int idx1 = 0,idx2 = 0;
		while(pos<len)
		{
			if(isalpha(s[pos]))
			{
				t[idx1][idx2] = s[pos];
				idx2++;
			}
			else
			{
				if(isalpha(s[pos-1]))
				{
					t[idx1][idx2] = '\0';
					idx1++;
				}
				idx2 = 0;
			}
			pos++;
		}
		t[idx1][idx2] = '\0';
		printf("case #%d:\n",kase);
		qsort(t,idx1,sizeof(t[0]),mycmp);
		printf("%s ",t[0]);
		for(int i=1;i<idx1;i++)
		{
			if(strcmp(t[i-1],t[i])!=0) printf("%s ",t[i]);
		}
		putchar('\n');
	}
	return 0;
}