#include <stdio.h>
#include <stdlib.h>

typedef struct Team{
    int num;//编号
    int wins;//胜场
    int lose;//负场
    int score;//积分
}T;

T* newTeams(int n)
{
    T* t;
    for(int i = 1; i <= n+1; i++)
    {
        t[i].num = i;
        t[i].wins = 0;
        t[i].lose = 0;
        t[i].score = 0;
    }
    return t;
}

int cmp(const void *_a,const void *_b)
{
    T *a = (T*)_a;
    T *b = (T*)_b;
    if((a->score) > (b->score)) return -1;
    else if(a->score == b->score) return (b->wins - a->wins);
    else if(a->score == b->score && a->wins == b->wins) return (a->lose - b->lose);
    else return (a->num - b->num);
}

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    while(n != 0 || m != 0)
    {
        T* t = newTeams(n);

        for(int i = 0; i < m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c>0)
            {
                t[a].wins++;
                t[b].lose++;
                t[a].score+=3;
                t[b].score--;
            }
            else if(c==0)
            {
                t[a].score++;
                t[b].score++;
            }
            else
            {
                t[b].wins++;
                t[a].lose++;
                t[b].score+=3;
                t[a].score--;
            }
        }
        qsort(t,n,sizeof(int),cmp);
        for(int i = 1; i <= n; i++)
        {
            printf("%d ",t[i].num);
        }
        printf("\n");
        scanf("%d %d",&n,&m);
    }
    return 0;
}
