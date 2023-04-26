#include <stdio.h>
#include <stdlib.h>

struct team
{
	int number;
	int score;
	int win;
	int lose;
};

int cmp(const void *p1,const void *p2)
{
	struct team *P1=(struct team*)p1,*P2=(struct team*)p2;
	if(P1->score>P2->score) return -1;
	else if(P1->score<P2->score) return 1;
	else
	{
		if(P1->win>P2->win) return -1;
		else if(P1->win<P2->win) return 1;
		else
		{
			if(P1->lose<P2->lose) return -1;
			else if(P1->lose>P2->lose) return 1;
			else return P1->number-P2->number;
		}
	}
}

int main()
{
	int n,m;
	struct team t[10];
	for(int i=0;i<10;i++)
	{
		t[i].number=i+1;
		t[i].score=0;
		t[i].win=0;
		t[i].lose=0;
	}
	scanf("%d%d",&n,&m);
	while(n!=0)
	{
		int a,b,c;
		for(int j=0;j<m;j++)
		{
			scanf("%d%d%d",&a,&b,&c);
			switch(c)
			{
				case 1:{
					for(int i=0;i<10;i++)
					{
						if(t[i].number==a)
						{
							t[i].score+=3;
							t[i].win++;
						}
						if(t[i].number==b)
						{
							t[i].score--;
							t[i].lose++;
						}
					}
					break;
				}
				case -1:{
					for(int i=0;i<10;i++)
					{
						if(t[i].number==b)
						{
							t[i].score+=3;
							t[i].win++;
						}
						if(t[i].number==a)
						{
							t[i].score--;
							t[i].lose++;
						}
					}
					break;
				}
				case 0:{
					for(int i=0;i<10;i++)
					{
						if(t[i].number==a)
						{
							t[i].score++;
						}
						if(t[i].number==b)
						{
							t[i].score++;
						}
					}
					break;
				}	
			}
		}
		struct team *p=t;
		qsort(p,n,sizeof(t[0]),cmp);
		for(int i=0;i<n;i++)
		{
			printf("%d ",t[i].number);
		}
		printf("\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}