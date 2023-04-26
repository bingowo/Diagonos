#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int number;
    int score;
    int win;
    int lose;
}team;
int cmp(const void *a,const void *b)
{
    team *p1,*p2;
    p1=(team*)a;
    p2=(team*)b;
    if(p1->score==p2->score)
    {
        if(p1->win==p2->win)
        {
            if(p1->lose==p2->lose)
            {
                return p1->number-p2->number;
            }
            return p1->lose-p2->lose;
        }
        return p2->win-p1->win;
    }
    return p2->score-p1->score;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(n!=0||m!=0)
    {
       team t[n];
    for(int i=0;i<n;i++)
    {
        t[i].number=i+1;
        t[i].score=0;
        t[i].win=0;
        t[i].lose=0;
    }
    int a,b,c;
    for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                t[a-1].win++;
                t[b-1].lose++;
                t[a-1].score+=3;
                t[b-1].score--;
            }
            if(c==-1)
            {
                t[a-1].lose++;
                t[b-1].win++;
                t[a-1].score--;
                t[b-1].score+=3;
            }
            if(c==0)
            {
                t[a-1].score++;
                t[b-1].score++;
            }
        }
    qsort(t,n,sizeof(t[0]),cmp);
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",t[i].number);
    }
    printf("%d\n",t[n-1].number);
    scanf("%d%d",&n,&m);
    }
    return 0;
}
