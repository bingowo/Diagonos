#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
long long len;
int cmp(const void *e1,const void *e2)
{
	int i=0;
	char *a=*(char **)e1,*b=*(char **)e2,*home1=0,*home2=0;
	while(*(a+i)!='@')
		i++;
	home1=a+i+1;
	i=0;
	while(*(b+i)!='@')
		i++;
	home2=b+i+1;
	if(strcmp(home1,home2)==0)
		return strcmp(b,a);
	else
		return strcmp(home1,home2);
}
int main()
{
	char **email;
	scanf("%d",&n);
	email=(char **)malloc(n*sizeof(char *));
	char s[1000001],*p=0;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		len=strlen(s);p=(char *)malloc(len+1);
		strcpy(p,s);
		*(email+i)=p;	
	} 
	qsort(email,n,sizeof(char *),cmp);
	for(int i=0;i<n;i++)
		printf("%s\n",email[i]);
	for(int i=0;i<n;i++)
	{
		p=email[i];
		free(p);
	}
	free(email);
	return 0;
 } 