#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char number[12];
	int sum;
}Stu;
int cmp(const void*a,const void*b)
{
	const Stu*x=a,*y=b;
	if(x->sum==y->sum)
	{
		return strcmp(x->number,y->number);
	}

	else
	{
		return y->sum-x->sum;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int i,j,k,n,m,g,num,que;
	for(i=0;i<t;i++)
	{
		int score[11];
		Stu stus[500];
		int cnt=0;
		printf("case #%d:\n",i);
		scanf("%d%d%d",&n,&m,&g);
		for(j=1;j<=m;j++)
		{
			scanf("%d",&score[j]);
		}
		for(j=0;j<n;j++)
		{
			scanf("%s",stus[j].number);
			stus[j].sum=0;
			scanf("%d",&num);
			for(k=0;k<num;k++)
			{
				scanf("%d",&que);
				stus[j].sum+=score[que];
			}
			if(stus[j].sum>=g)
			{
				cnt++;
			}
		}
		qsort(stus,n,sizeof(Stu),cmp);
		printf("%d\n",cnt);
		for(j=0;j<cnt;j++)
		{
			printf("%s %d\n",stus[j].number,stus[j].sum);
		}
	}
	
	return 0;
} 