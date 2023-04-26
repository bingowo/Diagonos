#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
	const char* s1=(char*)a,*s2=(char*)b;
	int s1num=-100000000,s2num=-100000000;
	int i;
	for(i=0;i<strlen(s1);i++)if(s1[i]<='9')
	{
		sscanf(s1+i,"%d",&s1num);
		break;
	}
	
	for(i=0;i<strlen(s2);i++)if(s2[i]<='9')
	{
		sscanf(s2+i,"%d",&s2num);
		break;
	}
	
	if(s1num!=s2num)return s1num-s2num;
	return strcmp(s1,s2);
}

int main()
{
	int i,j,k;
	int len=0;
	char strlist[100][40];
	while(~scanf("%s",&strlist[len++]));
	qsort(strlist,len,40*sizeof(char),cmp);
	for(i=0;i<len;i++)printf("%s ",strlist[i]);
	return 0;
}