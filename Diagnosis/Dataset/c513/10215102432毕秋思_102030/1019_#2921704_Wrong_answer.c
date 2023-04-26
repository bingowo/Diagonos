#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TEAM
{
    int num;
    int score;
    int win;
    int lose;
}team[20];

int cmp(const void *q1,const void *q2)
{
    struct TEAM *p1=(struct TEAM*)q1;
    struct TEAM *p2=(struct TEAM*)q2;
    if(p1->score<p2->score) return 1;
    else if(p1->score>p2->score) return -1;
    else if(p1->score==p2->score)
    {
        if(p1->win<p2->win) return 1;
        else if(p1->win>p2->win) return -1;
        else if(p1->win==p2->win)
        {
            if(p1->lose>p2->lose) return 1;
            else if(p1->lose<p2->lose) return -1;
            else if(p1->lose==p2->lose)
            {
                if(p1->num>p2->num) return 1;
                else return -1;
            }
        }
    }
}

int main()
{
    while(1)
    {
        int n=0,m=0;
        scanf("%d %d",&n,&m);
        if(n==m==0) break;
        for(int i=1;i<=20;i++)
        {
            team[i].num=i;
            team[i].score=0;
            team[i].win=0;
            team[i].lose=0;
        }
        for(int i=0;i<m;i++)
        {
            int a=0,b=0,c=0;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                team[a].score+=3;
                team[a].win+=1;
                team[b].score-=1;
                team[b].lose+=1;
            }
            else if(c==-1)
            {
                team[a].score-=1;
                team[a].lose+=1;
                team[b].score+=3;
                team[b].win+=1;
            }
            else if(c==0)
            {
                team[a].score+=1;
                team[b].score+=1;
            }
            qsort(team,n,sizeof(struct TEAM),cmp);
            for(int j=1;j<n;j++)
                printf("%d ",team[j].num);
            printf("%d\n",team[n].num);
        }
    }
    return 0;
}
