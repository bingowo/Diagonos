#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TEAM{
    int num;
    int score;
    int win;
    int lose;
}team[11];

int cmp(const void *q1,const void *q2)
{
    struct TEAM *p1=(struct TEAM*)q1;
    struct TEAM *p2=(struct TEAM*)q2;
    if(p1->score==p2->score)
    {
        if(p1->win==p2->win)
        {
            if(p1->lose==p2->lose)
            {
                return(p1->num - p2->num);
            }
            return(p1->lose - p2->lose);
        }
        return(p2->win - p1->win);
    }
    return(p2->score - p1->score);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(n!=0||m!=0)
    {
        for(int i=0;i<10;i++)
        {
            team[i].num=i+1;
            team[i].score=0;
            team[i].win=0;
            team[i].lose=0;
        }
        for(int i=0;i<m;i++)
        {
            int a=0,b=0,c=0;
            scanf("%d%d%d",&a,&b,&c);
            if(c==1)
            {
                team[a-1].score+=3;
                team[a-1].win++;
                team[b-1].score--;
                team[b-1].lose++;
            }
            else if(c==-1)
            {
                team[a-1].score--;
                team[a-1].lose++;
                team[b-1].score+=3;
                team[b-1].win++;
            }
            else if(c==0)
            {
                team[a-1].score++;
                team[b-1].score++;
            }
        }
        qsort(team,n,sizeof(struct TEAM),cmp);
        int j=0;
        for(j=0;j<n-1;j++)
            printf("%d ",team[j].num);
        printf("%d\n",team[j].num);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
