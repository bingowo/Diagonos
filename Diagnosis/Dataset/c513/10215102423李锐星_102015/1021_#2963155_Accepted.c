#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char a[27],b[27];
int comp(const void*x,const void*y)
{
	char *m=(char*)x,*n=(char*)y;
	char s1[21],s2[21];
	int l,j;
	l=strlen(m);
	for(j=0;j<l;j++)
		s1[j]=b[toupper(m[j])-'A'];
	s1[j]='\0';
	
	l=strlen(n);
	for(j=0;j<l;j++)
		s2[j]=b[toupper(n[j])-'A'];
	s2[j]='\0';
	return strcmp(s1,s2);
}
int main()
{
	char s[100][21],ch;
	int i,j;
	while(scanf("%s",&a)!=-1)
	{
	for(i=0;i<26;i++)
		b[a[i]-'A']='A'+i;
	i=0;
	while(1)
	{
	scanf("%s",s[i]);
	i++;
	ch=getchar();
	if(ch=='\n')break;
	}
	qsort(s,i,sizeof(char[21]),comp);
	j=0;
	printf("%s",s[j]);
	for(j=1;j<i;j++)
	printf(" %s",s[j]);
	printf("\n");
	}
return 0;
}		
