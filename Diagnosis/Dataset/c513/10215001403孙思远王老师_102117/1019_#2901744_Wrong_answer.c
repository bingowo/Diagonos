#include <stdio.h>
#include <stdlib.h>

struct te
{
    int num;
    long long int score;
    int win;
    int lose;
};

int cmp(const void* x,const void* y)
{
    struct te *a,*b;
    a=(struct te*)x;
    b=(struct te*)y;
    if(a->score!=b->score)
        {
            if(b->score>a->score)
                return 1;
            else 
                return 0;
        }
    else if(a->win!=b->win)
        return b->win-a->win;
    else if(a->lose!=b->lose)
        return a->lose-b->lose;
    else
        return a->num-b->num;
}

int main()
{
    int n=1,m=1,i;
    while(n!=0&&m!=0)
    {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0) break;
        struct te team[n];
        for(i=0;i<n;i++)
        {
            team[i].num=i+1;
            team[i].score=0;
            team[i].win=0;
            team[i].lose=0;
        }
        int a,b,c;
        for(i=0;i<m;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&c);
            a--;
            b--;
            if(c==1)
            {
                team[a].score+=3;
                team[a].win++;
                team[b].score--;
                team[b].lose++;
            }
            else if(c==-1)
            {
                team[b].score+=3;
                team[b].win++;
                team[a].score--;
                team[a].lose++;
            }
            else if(c==0)
            {
                team[a].score++;
                team[b].score++;
            }
        }
        qsort(team,n,sizeof(team[1]),cmp);
        for(i=0;i<n;i++)
        {
            printf("%d",team[i].num);
            if(i<n-1)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}
