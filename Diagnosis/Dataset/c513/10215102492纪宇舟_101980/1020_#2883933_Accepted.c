#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int TYPE;
typedef struct{
	char date[20],time[10],name[100];
	int size;
}DOC;
int cmp(const void* a,const void* b)
{
	DOC x=*(DOC*)a;DOC y=*(DOC*)b;
	if(TYPE==1)return strcmp(x.name,y.name);
	if(TYPE==2)
	{
		if(x.size<y.size)return -1;
		else if(x.size==y.size)return strcmp(x.name,y.name);
		else return 1;
	}
	if(strcmp(x.date,y.date)<0)return -1;
	else if(strcmp(x.date,y.date)==0)
	{
		if(strcmp(x.time,y.time)<0)return -1;
		else if(strcmp(x.time,y.time)==0)return strcmp(x.name,y.name);
		else return 1;
	}
	else return 1;
}
int main()
{
	int n,flag=0;
	char pro[10];DOC doc[105];
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		if(flag)printf("\n");flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%s%s",doc[i].date,doc[i].time);
			scanf("%d%s",&doc[i].size,doc[i].name);
		}
		scanf("%s",pro);scanf("%s",pro);
		if(pro[1]=='N')TYPE=1;
		else if(pro[1]=='S')TYPE=2;
		else TYPE=3;
		qsort(doc+1,n,sizeof(DOC),cmp);
		for(int i=1;i<=n;i++)printf("%s %s %16d %s\n",doc[i].date,doc[i].time,doc[i].size,doc[i].name); 
	}
	return 0;
}