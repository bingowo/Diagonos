#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int win;
    int lose;
    int score;
    int number;
}Team;


int cmp(const void* a,const void *b)
{
    if((*(Team *)a).score!=(*(Team *)b).score)
        return (*(Team *)a).score-(*(Team *)b).score;
    else if((*(Team *)a).win!=(*(Team *)b).win)
        return (*(Team *)a).win-(*(Team *)b).win;
    else if((*(Team *)a).lose!=(*(Team *)b).lose)
        return (*(Team *)a).lose-(*(Team *)b).lose;
    else
        return (*(Team *)a).number-(*(Team *)b).number;
}

int main()
{
    int n,m;
    Team team[11];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0 && m==0)
            break;
        else
        {
    for(int i=1;i<n+1;i++)
    {
    team[i].number=i;
    team[i].lose=0;
    team[i].win=0;
    team[i].score=0;
    }
    for(int i=0;i<m;i++)
    {
        int num1,num2,res;
        scanf("%d%d%d",&num1,&num2,&res);
        //team[num1].number=num1;
        //team[num2].number=num2;
        if(res==1)
        {
            team[num1].win+=1;
            team[num1].score+=3;
            team[num2].lose+=1;
            team[num2].score-=1;
        }
        else if(res==-1)
        {
            team[num2].win+=1;
            team[num2].score+=3;
            team[num1].lose+=1;
            team[num1].score-=1;
        }
        else
        {
            team[num1].score+=1;
            team[num2].score+=1;
        }
    }
    qsort(team,n,sizeof(Team),cmp);
    for(int i=1;i<n;i++)
    printf("%d ",team[i].number);
    printf("%d\n",team[n].number);
    }
    }
    return 0;
}
