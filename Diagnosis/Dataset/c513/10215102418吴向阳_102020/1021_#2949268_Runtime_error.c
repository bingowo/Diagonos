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
	while(scanf("%s",s)!=EOF)
	{
		for(int j=0;j<26;j++)
		{
			p[s[j]-'a']=j;
		}
		char str[2200];
		char a[100][21];
		gets(str);
		while(1)
		{ 
			int count=0,i=0,j=0;
			while(str[i]!=' '&&str[i]) a[count][j++]=str[i++];
			a[count][j]='\0';
			count++;
			if(!str[i]) break; 
			else i++;
		qsort(a,count,sizeof(a[0]),cmp);
		for (int j=0;j<count;j++)
		{
			printf("%s ",a[j]);
		} 
		printf("\n");
		}
	}
	return 0;
}