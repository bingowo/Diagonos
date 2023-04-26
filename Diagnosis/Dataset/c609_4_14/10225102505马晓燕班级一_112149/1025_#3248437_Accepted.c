#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int num; int sco;int win;int los;
}team;

int cmp(const void* a,const void* b)
{
	team *x = (team*)a, *y = (team*)b;
	if(x->sco == y->sco)
	{
		if(x->win == y->win)
		{
			if(x->los == y->los)
				return x->num - y->num;
			else
				return x->los - y->los;
		}
		else
			return y->win - x->win;
	}
	else
		return y->sco - x->sco;
}
int main()
{
	int n,m;
//	scanf("%d %d",&n,&m);
	
	while(scanf("%d %d",&n,&m))
	{
	    if(n == 0 && m == 0)
			break;
		
		team* p = (team*)calloc(n+1,sizeof(team));
		for(int i=1;i<=n;i++)
		{
			p[i].num = i;
			//p[i].sco = 0,p[i].win = 0,p[i].los = 0;
		}
		
		int a,b,c;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			switch (c) {
			case 1:
				p[a].sco += 3,p[b].sco--;
				p[a].win++,p[b].los++;
//				printf("%d %d %d %d\n",a,p[a].sco,b,p[b].sco);
				break;
			case -1:
				p[b].sco += 3,p[a].sco--;
				p[b].win++,p[a].los++;
//				printf("%d %d %d %d\n",a,p[a].sco,b,p[b].sco);
				break;
			case 0:
				p[b].sco ++,p[a].sco++;
//				printf("%d %d %d %d\n",a,p[a].sco,b,p[b].sco);
				break;
			}
			
		}
		qsort(p+1,n,sizeof(team),cmp);
		
		for(int i=1;i<=n;i++)
		{
			printf("%d%c",p[i].num,i==n?'\n':' ');
		}
	//	printf("%d\n",p[n].num);
		
		free(p);
//		scanf("%d %d",&n,&m);
		
	}
	
	return 0;
}