#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
	const char* s1=(char*)a,*s2=(char*)b;
	int s1ch[128],s2ch[128],s1chs=0,s2chs=0;
	int i;
	memset(s1ch,0,128*sizeof(int));
	memset(s2ch,0,128*sizeof(int));
	for(i=0;*(s1+i)!='\0';i++)if(s1ch[*(s1+i)]==0)
	{
		s1ch[*(s1+i)]=1;
		s1chs++;
	}
	for(i=0;*(s2+i)!='\0';i++)if(s2ch[*(s2+i)]==0)
	{
		s2ch[*(s2+i)]=1;
		s2chs++;
	}
	if(s1chs!=s2chs)return s2chs-s1chs;
	return strcmp(s1,s2);
}

int main()
{
	int i,j,k;
	int c,cases,strnum;
	char strlist[1000][1000];
	
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		scanf("%d",&strnum);
		for(i=0;i<strnum;i++)scanf("%s",&strlist[i]);//printf("%s",strlist[0]);
		qsort(strlist,strnum,1000*sizeof(char),cmp);//printf("%s",strlist[0]);
		printf("case #%d:\n",c);
		for(i=0;i<strnum;i++)printf("%s\n",strlist[i]);
	}
	
	return 0;
}