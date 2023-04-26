#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int order=0;

typedef struct file
{
	char date[11];
	char time[6];
	int size;
	char name[65];
}F;

int cmp(const void *a,const void *b)
{
	const F file1=*(F*)a,file2=*(F*)b;
	if(order==3)
	{
		if(strcmp(file1.date,file2.date)!=0)return strcmp(file1.date,file2.date);
		if(strcmp(file1.time,file2.time)!=0)return strcmp(file1.time,file2.time);
	}
	else if(order==2)if(file1.size!=file2.size)return file1.size-file2.size;
	return strcmp(file1.name,file2.name);
}

int main()
{
	int i,j=0,k;
	int len=0;
	F flist[100];
	char command[12];
	while(~scanf("%d",&len))
	{
		if(j==1)putchar('\n');
		for(i=0;i<len;i++)scanf("%s %s %d %s",&flist[i].date,&flist[i].time,&flist[i].size,&flist[i].name);
		scanf("%*s %s",&command);
		if(strcmp(command+1,"NAME")==0)order=1;
		if(strcmp(command+1,"SIZE")==0)order=2;
		if(strcmp(command+1,"TIME")==0)order=3;
		qsort(flist,len,sizeof(F),cmp);
		for(i=0;i<len;i++)printf("%s %s %16d %s\n",flist[i].date,flist[i].time,flist[i].size,flist[i].name);
		j=1;
	}
	return 0;
}