#include <stdio.h>
#include <stdlib.h>


struct Team
{
    int num;//编号
    int wins;//胜场
    int lose;//负场
    int score;//积分
}t[15];

int cmp(const void *_a,const void *_b)
{
    struct Team a,b;
    a = *((struct Team*)_a);
    b = *((struct Team*)_b);
    if(a.score != b.score) return b.score - a.score;
    else
    {
        if(a.wins!=b.wins) return b.wins - a.wins;
        else
        {
            if(a.lose!=b.lose) return a.lose - b.lose;
            else return a.num - b.num;
        }
    }

}

int main()
{
    int n, m;
    while(scanf("%d %d",&n,&m)!=EOF && n != 0 || m != 0)
    {
        for(int i = 1; i <= n; i++)
        {
            t[i].num = i;
            t[i].wins = 0;
            t[i].lose = 0;
            t[i].score = 0;
        }
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
        qsort(t+1,n,sizeof(t[0]),cmp);
        for(int i = 1; i <= n; i++)
        {
            printf("%d ",t[i].num);
        }
        printf("\n");
    }
    return 0;
}
