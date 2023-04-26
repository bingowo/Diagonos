#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int table[256];
typedef struct{
	char st[21];
	int LEN;
}STR;
int cmp(const void* a,const void* b)
{
	STR x=*(STR*)a;STR y=*(STR*)b;
	for(int i=0;i<x.LEN&&i<y.LEN;i++)
	{
		if(table[x.st[i]]<table[y.st[i]])return -1;
		else if(table[x.st[i]]>table[y.st[i]])return 1;
		if(i==x.LEN-1)return -1;
		if(i==y.LEN-1)return  1;
	}
}
int main()
{
	STR str[101];
	char order[30],s[2005];
	while(scanf("%s\n",order)!=EOF)
	{
		for(int i=0;i<26;i++)
		{
			table[order[i]]=i;
			table['a'+order[i]-'A']=i;
		}
		gets(s);int len=strlen(s);
		int n=0,L=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]!=' ')str[n].st[L++]=s[i];
			if(s[i]==' '||i==len-1)
			{
				str[n].st[L]='\0';str[n].LEN=L;
				++n;L=0;
			}
		}
		qsort(str,n,sizeof(STR),cmp);
		for(int i=0;i<n;i++)
		{
			printf("%s",str[i].st);
			if(i!=n-1)printf(" ");
			else printf("\n");
		}
	}
	return 0;
}