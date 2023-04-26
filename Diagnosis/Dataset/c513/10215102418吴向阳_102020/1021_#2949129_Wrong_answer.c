#include <stdio.h>
#include <stdlib.h>
int p[26];

int cmp(const void *a,const void *b)
{
	char *s1,*s2;char ch1,ch2;
	s1=(char *)a;s2=(char *)b;
	while(*s1&&*s2)
	{
		ch1=(*s1)>='a'?*s1-32:*s1;
		ch2=(*s2)>='a'?*s2-32:*s2;
		if(p[ch1-'A']!=p[ch2-'A'])
			return p[ch1-'A']-p[ch2-'A'];
		else {s1++;s2++;}
	}
	if(*s1==0) return -1; 
	else return 1;
}

int main()
{
	char s[27];
	int p[26];
	char t[110][30];
	while(scanf("%s",s)!=EOF)
	{
		int i=0;
		for(int j=0;j<26;j++)
		{
			p[s[i]-'a']=i;
		}
		while(scanf("%s",t[i++])!=EOF);
		qsort(t[0],i,sizeof(t[0]),cmp);
		for (int j=0;j<i;j++)
		{
			printf("%s ",t[j]);
		} 
		printf("\n");
	}
	return 0;
}