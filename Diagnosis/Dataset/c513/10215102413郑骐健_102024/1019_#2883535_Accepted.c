#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct team { int win, loss, score, name; } Team;

int cmp(const void*p1 ,const void*p2)
{
    Team* p = (Team*)p1;
    Team* p_ = (Team*)p2;
    if (p->score < p_->score)return 1;
    else if (p->score == p_->score)
    {
        if (p->win < p_->win) return 1;
        else if (p->win == p_->win)
        {
            if (p->loss > p_->loss)
            {
                return 1;
            }
            else if (p->loss == p_->loss)
            {
                return p->name - p_->name;
            }
            else return -1;
        }
        else return -1;
    }
    else return -1;
}
int main()
{
    int teams, games;
    while (scanf("%d%d", &teams, &games))
    {
        if ((teams == 0) && (games == 0))break;
        Team p[200];
        for (int i = 1;i <= teams;i++)
        {   p[i].name = i;
            p[i].score = 0;
            p[i].win = 0;
            p[i].loss = 0;
        }
        for (int m = 0;m < games;m++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (c == 0)
            {
                p[a].score++;
                p[b].score++;
            }
            else if (c > 0)
            {
                p[a].score += 3;
                p[b].score -= 1;
                p[a].win++;
                p[b].loss++;
            }
            else
            {
                p[a].score -= 1;
                p[b].score += 3;
                p[b].win++;
                p[a].loss++;
            }
        }
            qsort(&p[1], teams, sizeof(Team), cmp);
            for (int v = 1;v <= teams;v++)
            {
                printf("%d ", p[v].name);
            }
            printf("\n");
        
    }
    
    return 0;
}