#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
int containint(const char* s)
{
	char* str=s;
	int i,len=strlen(str);
	for(i=0;i<len;i++)if(isdigit(str[i]))break;
	if(i==len)return -1;
	else
	{
		char str2[10];
		int j=0;
		while(str[i]&&isdigit(str[i]))str2[j++]=str[i++];
		str2[j]=0;
		return atoi(str2);
	}
}
int strnumcmp(const void* a,const void* b)
{
	char *p1=*(char**)a,*p2=*(char**)b;
	int n1=containint(p1),n2=containint(p2);
	if(n1==n2)return strcmp(p1,p2);
	else
	{
	    if(n1>n2)return 1;
	    else return -1;
	}
}
int main()
{
	
	char** a;
	a=(char**)malloc(sizeof(char*)*110);
	int n=0,len,i;
	char s[40];char* p;
	while((scanf("%s",s))!=EOF)
	{
		len=strlen(s);
		p=(char*)malloc(len+1);
		strcpy(p,s);
		a[n++]=p;
	}
	qsort(a,n,sizeof(char*),strnumcmp);
	for(i=0;i<n;i++)printf("%s ",a[i]);
	for(i=0;i<n;i++){
		p=a[i];
		free(p);
	}
	free(a);
	return 0;
}