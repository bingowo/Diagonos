#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b)
{
	char *ax,*bx;
	ax=*((char**)a);bx=*((char**)b);
	int i=0,j=0;
	while(*(ax+i)!='@')i++;
	while(*(bx+j)!='@')j++;
	char *axx,*bxx;
	axx=ax+i+1;bxx=bx+j+1;
	if(strcmp(axx,bxx)!=0)return strcmp(axx,bxx);
	else return strcmp(bx,ax);
	
}
int main()
{
	int n;scanf("%d\n",&n);
	char** email;
	email=(char**)malloc(n*sizeof(char*));
	char s[1000001];char* p;
	int len;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		len=strlen(s);
		p=(char*)malloc(len+1);
		strcpy(p,s);
		email[i]=p;
	}
	qsort(email,n,sizeof(char*),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%s\n",email[i]);
	}
	for(int i=0;i<n;i++){p=email[i];free(p);}
	free(email);
	return 0;
}