#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct mailaddr
{
	char* username;
	char* hostname;
}MAIL;

int cmp(const void *a,const void *b)
{
	const MAIL s1=*(MAIL*)a,s2=*(MAIL*)b;
	if(strcmp(s1.hostname,s2.hostname)!=0)return strcmp(s1.hostname,s2.hostname);
	if(strcmp(s1.username,s2.username)!=0)return strcmp(s2.username,s1.username);
}

int main()
{
	int i,j,k;
	int len=0;
	scanf("%d",&len);
	MAIL maillist[1000000];
	char *data=malloc(200000*sizeof(char));
	char *datapos=data;
	for(i=0;i<len;i++)
	{
		scanf("%s",datapos);
		maillist[i].username=datapos;
		datapos=strchr(datapos,'@');
		*datapos='\0';
		datapos++;
		maillist[i].hostname=datapos;
		datapos+=strlen(datapos)+1;
	}
	qsort(maillist,len,sizeof(MAIL),cmp);
	for(i=0;i<len;i++)printf("%s@%s\n",maillist[i].username,maillist[i].hostname);
	free(data);
	return 0;
}