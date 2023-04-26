#include <stdio.h>
#include <stdlib.h> 
/**/

typedef struct{ int score;int win;int lose; int num;
} sit;

int cmp(const void *a,const void *b)
{
	sit **pa=(sit **)a;
	sit **pb=(sit **)b;
	if((*pa)->score==(*pb)->score)
	{
		if(((*pa)->win) < ((*pb)->win)) return 1;
		else if (((*pa)->win) >( (*pb)->win) )return -1;
		else 
		{
			if(((*pa)->lose) < ((*pb)->lose)) return -1;
			else if(((*pa)->lose )>( (*pb)->lose))return 1;
			else return pa-pb>0?1:-1;
		}
	}
	return ((*pb)->score)-((*pa)->score);
}


int main()
{
	while(1)
	{
		int n,m,a,b,c;
		scanf("%d %d",&n,&m);
		if(n==0&&m==0) break;
		sit *p=(sit *)malloc(sizeof(sit)*n);
		
		for(int j=0;j<n;j++)//初始化为0 
		{
			(p+j)->score=0;
			(p+j)->win=0;
			(p+j)->lose=0;
		}
		
		for (int i=1; i<=m; i++)//m为轮数 
		{
			scanf("%d %d %d",&a,&b,&c);
			switch (c)
			{
				case 1:
				{
				(p+a-1)->score+=3;
				(p+a-1)->win+=1;
				(p+b-1)->score-=1;
				(p+b-1)->lose+=1;
				break;
				}
				case -1:
				{
				(p+a-1)->score-=1;
				(p+a-1)->lose+=1;
				(p+b-1)->score+=3;
				(p+b-1)->win+=1;
				break;		
				}
				case 0:
				{
				(p+a-1)->score+=1;
				(p+b-1)->score+=1;
				break; 
				}
			}
		}
		
		
		sit* pp[10];
		for(int i=0; i<n; i++)
		{
			pp[i]=p+i;
			(p+i)->num=i+1;
		}
		qsort(pp,n,sizeof(sit*),cmp);
		for(int i=1; i<=n; i++)
		{
			if(i!=1) printf(" ");
			printf("%d",pp[i]->num);
		}
		
		
	}
	return 0;
}
	
 