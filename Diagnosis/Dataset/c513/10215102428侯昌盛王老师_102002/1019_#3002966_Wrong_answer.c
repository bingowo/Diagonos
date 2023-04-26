#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int point;
	int win;
	int lose;
	int num;
}team;
int cmp(const void*a,const void*b)
{
	team *p,*q;
	p=(team*)a;q=(team*)b;
	if((p->point)>(q->point)) return -1;
	else if((p->point)<(q->point)) return 1;
	else
	{
		
		if((p->win)>(q->win)) return -1;
		else if((p->win)<(q->win)) return 1;
		else
		{
			if((p->lose)>(q->lose)) return 1;
			else if((p->lose)<(q->lose)) return -1;
			else
			{
				if((p->num)>(q->num)) return 1;
				else if((p->num)<(q->num)) return -1;
			}
		}
	}
}
int main()
{
	int n,m,i;
	
	while(~scanf("%d %d",&n,&m)&&n!=0&&m!=0)
	{
		team t[11];
		memset(t,0,sizeof(t));
		for(i=0;i<n;i++)
		{
			t[i].num=i+1;
		}
		for(i=0;i<m;i++)
		{
			int a,b,c;
			
			scanf("%d %d %d",&a,&b,&c);
			if(c==1)
			{
				t[a-1].point+=3;
				t[a-1].win+=1;
				t[b-1].point-=1;
				t[b-1].lose+=1;
			}
			else if(c==-1)
			{
				t[a-1].point-=1;
				t[a-1].lose+=1;
				t[b-1].point+=3;
				t[b-1].win+=1;
			}
			else
			{
				t[a-1].point+=1;
				t[b-1].point+=1;
			}
			
		}
		//printf("%d\n",t[3].point);
		qsort(t,n,sizeof(t[0]),cmp);
		//printf("%d\n",t[3].point);
		int k=0;
		for(k;k<n;k++)
		{
			printf("%d ",t[k].num);
		}
		printf("\n");
	
		
	}
	return 0;
}