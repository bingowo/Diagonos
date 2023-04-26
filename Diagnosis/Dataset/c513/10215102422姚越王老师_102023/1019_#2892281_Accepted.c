#include<stdio.h>
#include<stdlib.h>
typedef struct{int num;int vic;int lose;int point;} team;
int cmp(const void* a,const void* b)
{
	team *ax=(team*)a,*bx=(team*)b;
	if(ax->point>bx->point)return -1;
	else if(ax->point<bx->point)return 1;
	else
	{
		if(ax->vic>bx->vic)return -1;
		else if(ax->vic<bx->vic)return 1;
		else
		{
			if(ax->lose>bx->lose)return 1;
			else if(ax->lose<bx->lose)return -1;
			else
			{
				if(ax->num>bx->num)return 1;
				else return -1;
			}
		}
	}
}
int main()
{
	int n,g;
	while((scanf("%d%d",&n,&g))!=EOF)
	{
		if(n==0&&g==0)return 0;
		team rank[n];
		for(int i=0;i<n;i++)
		{
			rank[i].num=i+1;
			rank[i].vic=0;
			rank[i].point=0;
			rank[i].lose=0;}
		for(int i=0;i<g;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(c==1)
			{
				rank[a-1].vic+=1;
				rank[a-1].point+=3;
				rank[b-1].lose+=1;
				rank[b-1].point-=1;}
			else if(c==-1)
			{
				rank[b-1].vic+=1;
				rank[b-1].point+=3;
				rank[a-1].lose+=1;
				rank[a-1].point-=1;
			}
			else
			{
				rank[a-1].point+=1;
				rank[b-1].point+=1;
			}
		}
		qsort(rank,n,sizeof(rank[0]),cmp);
		for(int i=0;i<n;i++)printf("%d ",rank[i].num);
		printf("\n");
	}
}