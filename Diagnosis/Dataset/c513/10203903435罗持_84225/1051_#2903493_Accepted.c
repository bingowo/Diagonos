#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int T;
char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		char s[111];
		int bit[1000] = {0};
		char res[200] = {0}; 
		scanf("%s",s);
		int len = strlen(s);
		int idx = 0;
		for(int i=0;i<len;i++)
		{
			char c = s[i];
			int mask = 128;
			for(int j=0;j<8;j++)
			{
				if(c&mask) bit[idx] = 1;
				idx++;
				mask >>= 1;
			}
		}
		while(idx%6!=0) idx++;
		int id = 0;
		for(int i=0;i<idx;i=i+6)
		{
			int num = 0;
			for(int j=0;j<6;j++)
				num = num*2+bit[i+j];
			res[id++] = table[num];
		}
		while(id%4!=0)
		{
			res[id++] = '=';
		}
		res[id] = '\0';
		printf("case #%d:\n",kase);
		printf("%s\n",res);
	}
	return 0;
}