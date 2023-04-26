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
    while(scanf("%d %d\n",&n,&m)!='0')
    {
        int i=0;
        if(m==0)
        {
            for(i=1;i<=n;i++)
            {
                printf("%d ",i);
                printf("\n");
            }
        }
        else
        { team t[n];
        for(i=0;i<n;i++)
        {
            t[i].num=i+1;
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
                t[a-1].win++;
                t[b-1].lose++;
                t[a-1].score+=3;
                t[b-1].score-=1;
            }
            if(c==0)
            {
                t[a-1].score++;
                t[b-1].score++;
            }
            if(c==-1)
            {
                t[b-1].win++;
                t[a-1].lose++;
                t[b-1].score+=3;
                t[a-1].score--;
            }
        }
        qsort(t,n,sizeof(t[0]),cmp);
        int j=0;
        for(j=0;j<n-1;j++)
        {
            printf("%d ",t[j].num);
        }
        printf("%d\n",t[j].num);
        }
    }
    return 0;
}