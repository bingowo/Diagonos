#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int name;
    int score;
    int lose_count;
    int win_count;
}team_info;

int cmp(const void* p1, const void* p2)
{
    team_info* a = (team_info*)p1;
    team_info* b = (team_info*)p2;
    if(a->score != b->score)
        return b->score - a->score;
    else
    {
        if(a->win_count != b->win_count)
            return b->win_count - a->win_count;
        else
        {
            if(a->lose_count != b->lose_count)
                return a->lose_count - b->lose_count;
            else
                return a->name - b->name;
        }
    }
}

int main()
{
    int n=0,m=0;
    while (scanf("%d %d", &n, &m) != EOF && !(n == 0 && m == 0))
    {
        team_info team_list[n];
        for(int i=0;i<n;i++)// initialize team_list
        {
            team_list[i].name=i+1;
            team_list[i].score=0;
            team_list[i].lose_count=0;
            team_list[i].win_count=0;
        }
        for(int i=0;i<m;i++)// handle data
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);getchar();
            if(c==1)
            {
                team_list[a-1].score+=3;
                team_list[a-1].win_count++;
                team_list[b-1].score-=1;
                team_list[b-1].lose_count++;
            }
            else if (c==-1)
            {
                team_list[b-1].score+=3;
                team_list[b-1].win_count++;
                team_list[a-1].score-=1;
                team_list[a-1].lose_count++;
            }
            else
            {
                team_list[a-1].score++;
                team_list[b-1].score++;
            }
        }
        qsort(team_list,n,sizeof(team_list[0]),cmp);
        for(int i=0;i<n;i++) 
            printf("%d%c",team_list[i].name,i != n-1? ' ' : '\n');
    }
    
    system("pause");
    return 0;
}