#include<stdio.h>
typedef struct team
{
    int num;
    int win;
    int lose;
    int score;
}team;

int main(void)
{
    int n,m;//球队数、比赛数
    scanf("%d %d\n",&n,&m);
    int i=0;
    team *t=(team*)malloc(sizeof(team)*(n));
    for(i=0;i<n;i++)
    {
        t[i].num=i;
        t[i].win=0;
        t[i].lose=0;
        t[i].score=0;
    }
    for(i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d\n",&a,&b,&c);
        if(c==1)
        {
            t[a].win++;
            t[b].lose++;
            t[a].score+=3;
            t[b].score-=1;
        }
        if(c==0)
        {
            t[a].score++;
            t[b].score++;
        }
        if(c==-1)
        {
            t[b].wins++;
            t[a].lose++;
            t[b].score+=3;
            t[a].score--;
        }
    }
    sort();
    int j=0;
    for(j=0;j<sizeof(t.score)/sizeof(t[0].score)-1;j++)
    {
        printf("%d ",t[j].s)
    }
    return 0;
}