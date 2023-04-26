#include<stdio.h>
#include<math.h>
#include<string.h>
struct stu 
{
	int num;
	int score;
	int win;
	int lose;	
}; 
int cmp(const void *a,const void *b)
{
	struct stu *m=(struct stu *)a;
	struct stu *n=(struct stu *)b;
	if(m->score!=n->score)  {return n->score-m->score;}
	else
	{
		if(m->win!=n->win)  {return n->win-m->win;}
		else
		{
			if(m->lose!=n->lose)  {return m->lose-n->lose;}
			else  {return m->num-n->num;}
		}
	}
};

int main()
{
	int m=1,n=1,a=0,b=0,c=0;
	scanf("%d %d",&n,&m);
	struct stu team[200];
	struct stu *p=team;
	while(m!=0||n!=0)
	{
		for(int i=0;i<n;i++)
		{
		    p[i].num=i+1;
			p[i].win=0;
        	p[i].lose=0;
		    p[i].score=0;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(c==1) {p[a-1].score+=3;p[a-1].win++;p[b-1].score--;p[b-1].lose++;}
			if(c==-1) {p[a-1].score--;p[a-1].lose++;p[b-1].score+=3;p[b-1].win++;}
			if(c==0) {p[a-1].score++;p[b-1].score++;}
		}
		qsort(p,n,sizeof(struct stu),cmp);
		for(int j=0;j<n;j++)
		{
			printf("%d ",p[j].num);
		}
		printf("\n"); 
		scanf("%d %d",&n,&m);
	}
	
	return 0;
	
	
 } 