#include<stdio.h>
#include<stdlib.h>
struct data
{
    int num;
    int score;
    int lose;
    int win;
};
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.score!=b.score)
    {
        return b.score-a.score;
    }
    else
    {
        if(a.win!=b.win)
        {
            return b.win-a.win;
        }
        else
        {
            if(a.lose!=b.lose)
            {
                return a.lose-b.lose;
            }
            else
            {
                return a.num-b.num;
            }
        }
    }
}

int main()
{
    for(int i=0;i<1000;i++)
    {
    	int n,m;
        scanf("%d%d",&n,&m);
        if(n!=0||m!=0)
        {
        	struct data team[n]; 
            for(int t=0;t<n;t++)
            {
                team[t].num=t+1;
                team[t].score=0;
                team[t].lose=0;
                team[t].win=0;
            }
            int a[3];
            for(int j=0;j<m;j++)
            {
                scanf("%d%d%d",&a[0],&a[1],&a[2]);
                if(a[2]==0)
            	{
                	for(int k=0;k<n;k++)
                	{
                    	if(team[k].num==a[0])
                    	{
                        	team[k].score=team[k].score+1;
                    	}
                    	if(team[k].num==a[1])
                    	{
                        	team[k].score=team[k].score+1;
                    	}
                	}
            	}
            	else if(a[2]==1)
            	{
                	for(int k=0;k<n;k++)
                	{
                    	if(team[k].num==a[0])
                    	{
                        	team[k].score=team[k].score+3;
                        	team[k].win=team[k].win+1;
                    	}
                    	if(team[k].num==a[1])
                    	{
                        	team[k].score=team[k].score-1;
                        	team[k].lose=team[k].lose+1;
                    	}
                	}
            	}
            	else
            	{
                	for(int k=0;k<n;k++)
                	{
                    	if(team[k].num==a[0])
                    	{
                        	team[k].score=team[k].score-1;
                        	team[k].lose=team[k].lose+1;
                    	}
                    	if(team[k].num==a[1])
                    	{
                        	team[k].score=team[k].score+3;
                        	team[k].win=team[k].win+1;
                    	}
                	}
            	}
            }
            
            qsort(team,n,sizeof(team[0]),cmp);
            for(int z=0;z<n-1;z++)
            {
            	printf("%d ",team[z].num);
			}
			printf("%d\n",team[n-1].num);
        }
        else
        {
            break;
        }
    }
    return 0;
    
}