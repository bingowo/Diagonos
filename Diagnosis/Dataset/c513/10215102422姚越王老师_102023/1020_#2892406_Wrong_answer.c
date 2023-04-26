#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{char date[1005];char time[1005];int s;char name[1005];} file;
int cmp1(const void* a,const void* b)//name
{
	file *ax=(file*)a,*bx=(file*)b;
	return strcmp(ax->name,bx->name);
}
int cmp2(const void* a,const void* b)//size
{
	file *ax=(file*)a,*bx=(file*)b;
	if(ax->s>bx->s)return 1;
	else return -1;
}
int cmp3(const void* a,const void* b)//time
{
	file *ax=(file*)a,*bx=(file*)b;
	if(strcmp(ax->date,bx->date)>0)return 1;
	else return strcmp(ax->time,bx->time);
}
int main()
{
	int n;
	while((scanf("%d",&n))!=EOF)
	{
		if(n==0)return 0;
		file list[n];
		for(int i=0;i<n;i++)
		{
			scanf("%s",list[i].date);
			scanf("%s",list[i].time);
			scanf("%d",&list[i].s);
			scanf("%s",list[i].name);
		}
		char way[1005];
		scanf("%s",way);
		scanf("%s",way);
		if(strchr(way,'A')!=0)qsort(list,n,sizeof(list[0]),cmp1);//name
		else if(strchr(way,'Z')!=0)qsort(list,n,sizeof(list[0]),cmp2);//size
		else if(strchr(way,'T')!=0)qsort(list,n,sizeof(list[0]),cmp3);//time
		for(int i=0;i<n;i++)
		{
			printf("%s ",list[i].date);
			printf("%s ",list[i].time);
			printf("%16d ",list[i].s);
			printf("%s\n",list[i].name);
		}
		printf("\n");
	}
}