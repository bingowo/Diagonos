#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
typedef struct{
	char stu[12];
	int qus[10];
	int num;
	int sco;
}QWQ; 

int cmp(const void*a,const void*b)
{
	QWQ*p1=(QWQ*)a;QWQ*p2=(QWQ*)b;
	if((p1->sco)>(p2->sco)) return -1;
	else if((p1->sco)<(p2->sco)) return 1;
	else
	{
		for(int k=0;k<11;k++)
		{
			if((p1->stu[k])>(p2->stu[k])) return 1;
			else return -1;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N,M,G;
		scanf("%d%d%d",&N,&M,&G);
		int A[10];
		for(int j=0;j<M;j++) scanf("%d",&A[j]);
		QWQ *p=(QWQ*)malloc(N*sizeof(QWQ));
		p->sco=0;
		p->num=0;
		for(int m=0;m<N;m++)
		{
			((p+m)->sco)=0;
			scanf("%s",(*(p+m)).stu);
			scanf("%d",&(p+m)->num);
			//printf("%d\n",(p+m)->num);
			for(int j=0;j<(p+m)->num;j++) 
			{
				scanf("%d",&(p+m)->qus[j]);
				//printf("  %d\n",(p+m)->qus[j]);
			}
			for(int j=0;j<(p+m)->num;j++)
			{
				//printf("%d\n",A[((p+m)->qus[j])-1]);
				((p+m)->sco)+=A[((p+m)->qus[j])-1];
				//printf("    %d   \n",((p+m)->sco));
			}
		}
		qsort(p,N,sizeof(QWQ),cmp);
		printf("case #%d:\n",i);
		int number=0;
		for(int j=0;j<N;j++)
		{
			if(((p+j)->sco)>=G) number++;
		}
		printf("%d\n",number);
		if(number>0)
			for(int j=0;j<N;j++)
			{
				printf("%s %d\n",(p+j)->stu,(p+j)->sco);
			}
		free(p);
	}
	return 0;
}