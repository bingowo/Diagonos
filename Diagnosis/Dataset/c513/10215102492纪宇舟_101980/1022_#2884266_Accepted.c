#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void* a,const void* b)
{
	char *p1=*(char**)a;char *p2=*(char**)b;
	char* l1=p1;char* l2=p2;
	while(*(l1++)!='@');while(*(l2++)!='@');
	if(strcmp(l1,l2)<0)return -1;
	else if(strcmp(l1,l2)==0)return -strcmp(p1,p2); 
	else return 1;
}
int main()
{
	int n;scanf("%d",&n);
	char** email=(char**)malloc((n+1)*sizeof(char*));
	char ipt[1000001];
	for(int i=0;i<n;i++)
	{
		scanf("%s",ipt);int len=strlen(ipt);
		char* p=(char*)malloc((len+1)*sizeof(char));
		strcpy(p,ipt);email[i]=p;
	}
	qsort(email,n,sizeof(char*),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%s\n",email[i]);
		free(email[i]);
	}free(email);
	return 0;
}