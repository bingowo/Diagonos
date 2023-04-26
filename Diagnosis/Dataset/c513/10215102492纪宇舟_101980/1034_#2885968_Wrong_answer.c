#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
double table[256];
int cmp(const void* a,const void* b)
{
	char x=*(char*)a;char y=*(char*)b;
	if(table[x]>table[y])return -1;
	else if(table[x]==table[y])
	{
		if(x>y)return -1;
		else return 1;
	}
	else return 1;
}
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		char s[105];
		for(int i=0;i<26;i++)
		{
			scanf("%lf",&table['a'+i]);
			table['A'+i]=table['a'+i];
		}
		scanf("%s",s);
		int n=strlen(s);
		qsort(s,n,sizeof(char),cmp);
		printf("case #%d:\n",ct++);
		for(int i=0;i<n;i++)printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}