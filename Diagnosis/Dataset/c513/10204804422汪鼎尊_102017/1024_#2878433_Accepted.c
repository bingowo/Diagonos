#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct stu
{
	char no[20];
	int score;
}STUDENT;

int cmp(const void *a,const void *b)
{
	STUDENT s1=*(STUDENT*)a,s2=*(STUDENT*)b;
	if(s1.score!=s2.score)return s2.score-s1.score;
	return strcmp(s1.no,s2.no);
	
}

int main()
{
	int i,j,k;
	int c,cases,len;
	int num,ques,line;
	int pts[11],pt;
	STUDENT stulist[500];
	
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		len=0;
		scanf("%d %d %d",&num,&ques,&line);
		for(i=1;i<=ques;i++)scanf("%d",&pts[i]);
		for(i=0;i<num;i++)
		{
			scanf("%s",&stulist[len].no);
			scanf("%d",&j);
			stulist[len].score=0;
			for(j--;j>=0;j--)
			{
				scanf("%d",&k);
				stulist[len].score+=pts[k];
			}
			if(stulist[len].score>=line)len++;
		}
		qsort(stulist,len,sizeof(STUDENT),cmp);
		printf("case #%d:\n",c);
		printf("%d\n",len);
		for(i=0;i<len;i++)printf("%s %d\n",stulist[i].no,stulist[i].score);
		//if(c!=cases-1)putchar('\n');
	}
	
	return 0;
}