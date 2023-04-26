#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int score;
    int win;
    int lose;
    int num;
} count;

int cmp(const void *q1,const void *q2)
{
    count *p1=(count *)q1;
    count *p2=(count *)q2;

    if(p1->score!=p2->score)
    {
        if(p1->score>p2->score) return -1;
        else return 1;
    }
    else
    {
        if(p1->win!=p2->win)
        {
            if(p1->win>p2->win) return -1;
            else return 1;
        }
        else
        {
            if(p1->lose!=p2->lose)
            {
                if(p1->lose<p2->lose) return -1;
                else return 1;
            }
            else
            {
                if(p1->num<=p2->num) return -1;
                else return 1;
            }
        }
    }
}

int main()
{
    int m,n;

    int a,b,c;

    while(scanf("%d %d\n",&n,&m))
    {
        if(n==0||m==0) break;

        count team[11]= {0};

        for(int i=1; i<=n; i++)
            team[i].num=i;

        for(int j=0; j<m; j++)
        {
            scanf("%d %d %d\n",&a,&b,&c);

            if(c==0)
            {
                team[a].score++;
                team[b].score++;
            }
            else if(c==1)
            {
                team[a].score+=3;
                team[b].score--;
                team[a].win++;
                team[b].lose++;
            }
            else if(c==(-1))
            {
                team[a].score--;
                team[b].score+=3;
                team[a].lose++;
                team[b].win++;
            }
        }

        qsort(team+1,n,sizeof(team[1]),cmp);

        for(int k=1; k<=n; k++)
            printf("%d ",team[k].num);
        printf("\n");
    }
    return 0;
}
