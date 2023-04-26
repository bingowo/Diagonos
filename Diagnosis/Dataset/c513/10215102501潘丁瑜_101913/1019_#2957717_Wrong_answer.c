#include <stdio.h>
#include <stdlib.h>

struct troop
{
    int index;
    int score;
    char win;
    char fail;
};

int cmp(const void *c , const void *d)
{
	struct troop *a=(struct troop *)c;
	struct troop *b=(struct troop *)d;
	if(a->score!=b->score)
		return a->score-b->score;
	else
	{
		if(a->win!=b->win)
			return a->win-b->win;
		else
		{
			if(a->fail!=b->fail)
				return b->fail-a->fail;
			else
				return a->index-b->index;
		}
	}
}


int main()
{
    int n,m;
    int i=0,j=0;
    int a,b;
    int c;
    char line[20];
    
    while(scanf("%d %d\n",&n,&m))
    {
    	if(n==0&&m==0)
			break;
    	struct troop T[128]={0,0,0,0};
    	for(i=1;i<=n;i++)
    	{
    		T[i].index=i;
		}
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            switch(c)
            {
            case 1:
                T[a].score+=3;
                T[a].win++;
                T[b].score--;
                T[b].fail++;
                break;
            case -1:
                T[a].score--;
                T[a].fail++;
                T[b].score+=3;
                T[b].win++;
                break;
            case 0:
                T[a].score++;
                T[b].score++;
                break;
            }
        }
        
        qsort(T,n+1,sizeof(T[0]),cmp);
        for(j=1;j<=n;j++)
        {
        	printf("%d",T[j].index);
        	if(j<n) printf(" ");
		}
		printf("\n");
    }
    return 0;
}