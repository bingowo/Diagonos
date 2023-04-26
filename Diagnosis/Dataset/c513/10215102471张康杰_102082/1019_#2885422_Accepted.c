#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int score;
    int a;
    int win;
    int lose;
}Tea;
int cmp(const void*a,const void*b)
{
    Tea*st1,*st2;
    st1 = (Tea*)a,st2 = (Tea*)b;
    if((st1->score) != (st2->score))
        return st2->score - st1->score;
    else
    {
        if(st1->win != st2->win)
            return st2->win - st1->win;
        else
        {
            if(st1->lose != st2->lose)
                return st1->lose - st2->lose;
            else
                return st1->a - st2->a;
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        Tea team[n];
        int a,b,c;
        for(int i = 0;i < n;i++)
        {
            team[i].score = 0;
            team[i].win = 0;
            team[i].lose = 0;
            team[i].a = i + 1;
        }
        for(int i = 0;i < m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c > 0)
            {
                team[a - 1].score += 3;
                team[b - 1].score -= 1;
                team[a - 1].win++;
                team[b - 1].lose++;
            }

            else if(c == 0)
            {
                team[a - 1].score += 1;
                team[b - 1].score += 1;
            }
            else
            {
                team[b - 1].score += 3;
                team[a - 1].score -= 1;
                team[b - 1].win++;
                team[a - 1].lose++;
            }
        }
        qsort(team,n,sizeof(team[0]),cmp);
        for(int i = 0;i < n;i++)
            printf("%d%c",team[i].a,(i == n - 1)?'\n':' ');
    }
    return 0;
}

