#include <stdio.h>
#include <stdlib.h>

struct Student
{
	long long number;
	int score;
}; 

int cmp(const void *a,const void *b)
{
	struct Student *p1=(struct Student *)a,*p2=(struct Student *)b;
	if(p1->score-p2->score>0) return -1;
	else if (p1->score-p2->score<0) return 1;
	else
	{
		if(p1->number-p2->number>0) return 1;
		else return -1;
	}
}
 
int main()
{
	int T,t;
	scanf("%d",&T);
	t=T;
	while(T)
	{
		int N,M,G;
		scanf("%d%d%d",&N,&M,&G);
		int a[10];
		struct Student student[N];
		for(int i=0;i<M;i++)
		{
			scanf("%d",&a[i]);
		}
		int AboveG=0;
		for (int i=0;i<N;i++)
		{
			int Score=0,right,x;
			long long stu;
			scanf("%lld%d",&stu,&right);
			for (int j=0;j<right;j++)
			{
				scanf("%d",&x);
				Score+=a[x-1];
			}
			if(Score >= G)
			{
				student[AboveG].number=stu;
				student[AboveG].score=Score;
				AboveG++;
			}
		}
		qsort(student,AboveG,sizeof(student[0]),cmp);
		printf("case #%d:\n%d\n",t-T,AboveG);
		for (int i=0;i<AboveG;i++)
		{
			long long m=student[i].number;
			while (m/10000000000==0) { printf("%d",0); m*=10;}
			printf("%lld %d\n",student[i].number,student[i].score);
		}
		T--;
	}
	return 0;
}