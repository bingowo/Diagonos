#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
int containint(const char* s)
{
	char* str=(char*)s;
	int i,len=strlen(str);
	for(i=0;i<len;i++)if(isdigit(str[i]))break;
	if(i==len)return 0;
	else
	{
		char str2[9];
		int j=0;
		while(str[i])str2[j++]=str[i++];
		str2[j]=0;
		return atoi(str2)+1;
	}
}
int strnumcmp(const void* a,const void* b)
{
	char *p1=*(char**)a,*p2=*(char**)b;
	if(containint(p1)&&containint(p2))
	{
		return containint(p1)-containint(p2);
	}
	else if(containint(p1)&&!containint(p2))return 1;
	else if(!containint(p1)&&containint(p2))return -1;
	else return strcmp(p1,p2);
}
int main()
{
	
	char** a;
	a=(char**)malloc(sizeof(char*)*100);
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