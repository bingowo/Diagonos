#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int name;
    int score;
    int win;
    int lose;
} Team;

int cmp(Team* a, Team* b)
{
    if (a->score != b->score) return b->score - a->score;
    else if (a->win != b->win) return b->win - a->win;
    else if (a->lose != b->lose) return a->lose - b->lose;
    else return a->name - b->name;
}

void Sort(Team *ps,int n)
{
    qsort(ps,n,sizeof(Team),cmp);
}

int main()
{
    int n,m;//球队数 比赛场数
    while ((scanf("%d%d",&n,&m)) != EOF && (n != 0 || m != 0) )
    {
        Team *t = (Team*)malloc(sizeof(Team) * (n+1));
        for (int i = 0; i <= n; i++)
        {
            t[i].lose = 0; t[i].name = 0; t[i].score = 0; t[i].win = 0;
        }
        if (m == 0) 
        {
            printf("1\n");
            break;
        }
        int a,b,c;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if (c == 1)
            {
                t[a].score = t[a].score + 3;
                t[b].score = t[b].score - 1;
                t[a].win++;
                t[b].lose++;
            }
            if (c == -1)
            {
                t[a].score = t[a].score - 1;
                t[b].score = t[b].score + 3;
                t[a].lose++;
                t[b].win++;
            }
            if (c == 0)
            {
                t[a].score = t[a].score + 1;
                t[b].score = t[b].score + 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            t[i].name = i;
        }
        Sort(t+1,n);
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c",t[i].name,i != n ? ' ':'\n');
        }
        free(t);
    }
    return 0;
}