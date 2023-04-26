#include <stdio.h>
#include <stdlib.h>
struct node
{
	int id;
	int score;
	int win;
	int lose;
}team[20];
int mycmp(const void* xx,const void* yy)
{
	struct node x = *((node *)xx);
	struct node y = *((node *)yy);
	if(x.score==y.score)
	{
		if(x.win == y.win)
		{
			if(x.lose == y.lose) return x.id > y.id;
			return x.lose>y.lose;
		}
		return x.win < y.win;
	}
	return x.score <y.score;
}
int main(void)
{
	int n,m;
	while(scanf("%d %d",&n,&m))
	{
		if(n==0 && m==0) break;
		for(int i=0;i<20;i++) 
		{
			team[i].score = 0;
			team[i].win = 0;
			team[i].lose = 0;
			team[i].id = i;
		}
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			if(z==1)
			{
				team[x].score+=3;
				team[x].win++;
				team[y].score--;
				team[y].lose++;
			}
			else if(z==-1)
			{
				team[x].score--;
				team[x].lose++;
				team[y].score+=3;
				team[y].win++;
			}
			else if(z==0)
			{
				team[x].score++;
				team[y].score++;
			}
		}
		qsort(team+1,n,sizeof(team[0]),mycmp);
		for(int i=1;i<=n;i++) printf("%d ",team[i].id);
		putchar('\n');
	}
	return 0;
}