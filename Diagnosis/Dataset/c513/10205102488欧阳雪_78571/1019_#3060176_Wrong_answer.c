#include<stdio.h>
#include<stdlib.h>
struct data{
	int grade;
	int win;
	int lose;
	int num;
};
int cmp(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	if(c.grade !=d.grade )
	{
		return(d.grade -c.grade);
	}
	else{
		if(c.win !=d.win )
		{
			return(d.win-c.win);
		}
		else{
			if(c.lose !=d.lose)
			{
				return(c.lose-d.lose);
			}
			else{
				return(c.num-d.num);
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	while(n==0||m==0)
	{
		scanf("%d %d",&n,&m);
	}
	while(n!=0&&m!=0)
	{
		int i=0;
		struct data team[10];
		for(i=0;i<10;i++)
		{
			team[i].grade =0;
			team[i].lose =0;
			team[i].win=0;
			team[i].num=i+1;
		}
		int a,b,c;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			a--;
			b--;
			if(c==1)
			{
				team[a].grade +=3;
				team[a].win +=1;
				team[b].grade -=1;
				team[b].lose +=1;
			}
			if(c==-1)
			{
				team[b].grade +=3;
				team[b].win +=1;
				team[a].grade -=1;
				team[a].lose+=1;
			}
			if(c==0)
			{
				team[a].grade +=1;
				team[b].grade+=1;
			}
		}
		qsort(team,n,sizeof(team[0]),cmp);
		for(i=0;i<n;i++)
		{
			printf("%d ",team[i].num );
		}
		printf("\n");
	/*	for(i=0;i<n;i++)
		{
			printf("%d %d %d %d",team[i].num ,team[i].grade,team[i].win,team[i].lose );
		printf("\n");
		}
		printf("\n");*/
		scanf("%d %d",&n,&m);
	}
}
 