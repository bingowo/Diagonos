#include<stdio.h>
#include<stdlib.h> 

typedef struct
{
    int point;
    int number;
    int win;
    int lose;
}team;

int cmp(const void *q1, const void *q2)
{
    team *t1 = (team*) q1;
    team *t2 = (team*) q2;
    if(t1->point == t2->point)
    {
        if(t1->win == t2->win)
        {
            if(t1->lose == t2->lose)
            {
                return(t1->number - t2->number);
            }
            return(t1->lose - t2->lose);
        }
        return(t2->win - t1->win);
    }
    return(t2->point - t1->point);
}

int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	while(n!=0&&m!=0)
	{
		team t[11];
		int i;
		for(i=0;i<n;i++)
		{
			t[i].point=0;
			t[i].win=0;
			t[i].lose=0;
		}
		for(i=1;i<11;i++)
		{
			t[i].number=i;
		}
		int a,b,c;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(c==1)
			{
				t[a].point+=3;
				t[b].point-=1;
				t[a].win+=1;
				t[b].lose+=1;
			}
			else if(c==-1)
			{
				t[b].point+=3;
				t[a].point-=1;
				t[b].win+=1;
				t[a].lose+=1;
			}
			else
			{
				t[a].point+=1;
				t[b].point+=1;
			}
		}
		qsort(t + 1, n, sizeof(team), cmp);
		for(i = 1; i <= n; i++)
    	{
    	    printf("%d ",t[i].number);
    	}
    	printf("\n");
		scanf("%d %d",&n,&m);
	}
	return 0;
} 