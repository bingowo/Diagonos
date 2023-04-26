#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char ID[12];
	int num;
	int rank[11];
	int grade;
};

int cmp(const void *_a,const void *_b);
int main()
{
	int T;
	scanf("%d",&T);
	for(int s=0;s<T;s++)
	{
		struct student a[501];
		int n,m,g;
		scanf("%d %d %d",&n,&m,&g);
		int weight[m];
		for(int i=0;i<m;i++)
		{
			scanf("%d",&weight[i]);
		}
		for(int i=0;i<n;i++)
		{	
			a[i].grade = 0;
			scanf("%s",a[i].ID);
			scanf("%d",&a[i].num);
			for(int j=0;j<a[i].num;j++)
			{
				scanf("%d",&a[i].rank[j]);
				a[i].grade += weight[a[i].rank[j]-1];
			}
		
		}
		qsort(a,n,sizeof(a[0]),cmp);
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(a[i].grade>=g)
			{
				count++;
			}
		}
		printf("case #%d:\n",s);
		printf("%d\n",count);
		for(int i=0;i<n;i++)
		{
			if(a[i].grade>=g)
			{
				printf("%s %d\n",a[i].ID,a[i].grade);
			}
			
		}
		
	}
}

int cmp(const void *_a,const void *_b)
{
	struct student p1,p2;
	p1 = *(struct student *)_a;
	p2 = *(struct student *)_b;
	if(p1.grade>p2.grade)
		return -1;
	else if(p1.grade == p2.grade)
	{
		return strcmp(p1.ID,p2.ID);
	}
	else
		return 1;
	
	
}