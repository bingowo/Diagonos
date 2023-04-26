#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char order[27];  //current problem: 1021

int cmp(const void *a,const void *b)
{
	int i;
	char s1[21],s2[21];
	strcpy(s1,*(char**)a);
	strcpy(s2,*(char**)b);
	for(i=0;i<21;i++)
	{
		if(s1[i]>='a')s1[i]-=32;
		if(s2[i]>='a')s2[i]-=32;
	}
	for(i=0;s1[i]==s2[i]&&s1[i]!='\0'&&s2[i]!='\0';i++);
	if(i>=20||s1[i]==s2[i])return 0;
	if(s1[i]=='\0')return -1;
	if(s2[i]=='\0')return 1;
	return -strlen(strchr(order,s1[i]))+strlen(strchr(order,s2[i]));
}

int main()
{
	int i,j,len,lenline;
	char *strarray[100],line[21000];
	while(~scanf("%s",&order))
	{
		getchar();
		gets(line);
		len=1;
		strarray[0]=line;lenline=strlen(line);
		for(i=0;i<lenline;i++)if(line[i]==' ')
		{
			strarray[len++]=(line+i+1);
			line[i]='\0';
		}
		qsort(strarray,len,sizeof(char*),cmp);
		for(i=0;i<len;i++)printf("%s%c",strarray[i],i==len-1?'\n':' ');
	}
	return 0;
}