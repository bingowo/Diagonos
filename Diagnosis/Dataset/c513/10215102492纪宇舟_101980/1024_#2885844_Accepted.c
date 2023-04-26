#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	int tol;
	char num[13];
}STU;
int cmp(const void* a,const void* b)
{
	STU x=*(STU*)a;STU y=*(STU*)b;
	if(x.tol>y.tol)return -1;
	else if(x.tol==y.tol)return strcmp(x.num,y.num);
	else return 1;
}
int main()
{
	int ct=0,T;scanf("%d",&T);
	int score[11];STU student[505];
	while(T--)
	{
		int N,M,G;scanf("%d%d%d",&N,&M,&G);
		for(int i=1;i<=M;i++)scanf("%d",&score[i]);
		for(int i=1;i<=N;i++)
		{
			student[i].tol=0;
			scanf("%s",student[i].num);
			int m,j;scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&j);student[i].tol+=score[j];
			}
		}
		qsort(student+1,N,sizeof(STU),cmp);
		printf("case #%d:\n",ct++);
		int cnt=0;
		for(int i=1;i<=N;i++)
		if(student[i].tol>=G)++cnt;
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%s %d\n",student[i].num,student[i].tol);
	}
	return 0;
}