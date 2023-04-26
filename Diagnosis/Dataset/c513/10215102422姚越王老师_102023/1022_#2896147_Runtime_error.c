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
	char *axx=ax+i+1,*bxx=bx+j+1;
	if(strcmp(axx,bxx)!=0)return strcmp(axx,bxx);
	else return strcmp(bx,ax);
	
}
int main()
{
	int n;scanf("%d",&n);
	char** email=(char**)malloc(n*sizeof(char*));
	char s[1000001];char* p;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		p=(char*)malloc(strlen(s)+1);
		strcpy(p,s);
		*(email+i)=p;
	}
	qsort(email,n,sizeof(char*),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%s\n",*email[i]);
	}
	for(int i=0;i<n;i++)free(*(email+i));
	free(email);
	return 0;
}