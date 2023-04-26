#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b)
{
	char *ax=*(char**)a,*bx=*(char**)b;
	int i,j;
	for(i=0;ax[i];i++)if(ax[i]=='@')break;
	for(j=0;bx[j];j++)if(bx[j]=='@')break;
	char *axx=ax+i+1,*bxx=bx+i+1;
	if(strcmp(axx,bxx)!=0)return strcmp(axx,bxx);
	else
	{
		ax[i]=0;bx[i]=0;
		return -strcmp(ax,bx);
	}
}
int main()
{
	int n;scanf("%d",&n);
	char** email=(char**)malloc(n*sizeof(char*));
	char s[1000001];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		char* p=(char*)malloc(strlen(s)+1);
		strcpy(p,s);
		*(email+i)=p;
	}
	qsort(email,n,sizeof(email[0]),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%s\n",*email[i]);
	}
	for(int i=0;i<n;i++)free(*(email+i));
	free(email);
	return 0;
}