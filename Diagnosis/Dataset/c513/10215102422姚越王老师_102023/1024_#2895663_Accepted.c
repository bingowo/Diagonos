#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{char num[1005];int point;} stu;
int cmp(const void* a,const void* b)
{
	stu *ax=(stu*)a,*bx=(stu*)b;
	if(ax->point>bx->point)return -1;
	else if(ax->point<bx->point)return 1;
	else return strcmp(ax->num,bx->num);
}
int main()
{
	int n;scanf("%d",&n);
	for(int cnt=0;cnt<n;cnt++)
	{
		int N,M,G;scanf("%d%d%d",&N,&M,&G);//学生数，题目数，分数线 
		int p[M];
		for(int i=0;i<M;i++)scanf("%d",&p[i]);
		stu a[N];
		for(int i=0;i<N;i++)a[i].point=0;
		for(int i=0;i<N;i++)//读取每个学生的数据 
		{
			scanf("%s",a[i].num);
			int n;scanf("%d",&n);//解出题目数 
			int que;//题号 
			for(int j=0;j<n;j++)
			{
				scanf("%d",&que);
				a[i].point+=p[que-1];
			}
		}
		qsort(a,N,sizeof(a[0]),cmp);
		printf("case #%d:\n",cnt);
		int cnt2=0;
		for(int i=0;i<N;i++)
		{
			if(a[i].point>=G)cnt2++;
		}
		printf("%d\n",cnt2);
		for(int i=0;i<N;i++)
		{
			if(a[i].point>=G)
			{
				printf("%s %d\n",a[i].num,a[i].point);
			}
		}
		
	}
	return 0;
}