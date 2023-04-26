#include<stdio.h>
typedef struct team
{
    int num;
    int win;
    int lose;
    int score;
}team;
int cmp(const void *a,const void *b)
{
    team *a1=(team *)a;
    team *b1=(team *)b;
    if(a1->score>b1->score) return -1;
    else if(a1->score<b1->score) return 1;
    else
    {
        if(a1->win>b1->win) return -1;
        else if(a1->win<b1->win) return 1;
        else
        {
            if(a1->lose>b1->lose) return 1;
            else if(a1->lose<b1->lose) return -1;
            else
            {
                if(a1->num>b1->num) return 1;
                else if(a1->num<b1->num) return -1;
            }
        }
    }
}
int main(void)
{
    int n,m;//球队数、比赛数
    scanf("%d %d\n",&n,&m)
    while(n!=0 || m!=0)
    {
        int i=0;
        team *t=(team*)malloc(sizeof(team)*(n+5));
        
        if(m==0)
        {
            for(i=1;i<=n;i++)
            {
                printf("%d ",i);
                printf("\n");
            }
        }
        else 
        for(i=1;i<=n;i++)
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
                t[b].win++;
                t[a].lose++;
                t[b].score+=3;
                t[a].score--;
            }
        }
        qsort(t,n,sizeof(t[0]),cmp);
        int j=0;
        for(j=0;j<n;j++)
        {
            printf("%d ",t[j].num);
        }
        printf("%d\n",t[j].num);
    }
    return 0;
}