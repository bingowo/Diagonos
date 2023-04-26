#include <stdio.h>
#include <stdlib.h>

struct T{
int teamnum;int win;int lose;int score;
};

int cmp(const void* a,const void* b)
{
    struct T* p1=*(struct T**)a;
    struct T* p2=*(struct T**)b;
    if(p1->score>p2->score)
    {
        return -1;
    }
    else if(p1->score<p2->score)
    {
        return 1;
    }
    else{
        if(p1->win>p2->win)
        {
            return -1;
        }
        else if(p1->win<p2->win)
        {
            return 1;
        }
        else{
            if(p1->lose<p2->lose)
            {
                return -1;
            }
            else if(p1->lose>p2->lose)
            {
                return 1;
            }
            else{
                return p1->teamnum-p2->teamnum;
            }
        }
    }
}

int main()
{
    int n,m;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)
        {
            break;
        }
        struct T* team[n+1];
        for(int i=0;i<n;i++)
        {
            team[i]=(struct T*)malloc(sizeof(struct T));
            team[i]->lose=0;
            team[i]->score=0;
            team[i]->win=0;
            team[i]->teamnum=i+1;
        }
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                team[a-1]->score+=3;
                team[a-1]->win+=1;
                team[b-1]->score+=1;
                team[b-1]->lose+=1;
            }
            else if(c==-1)
            {
                team[b-1]->score+=3;
                team[b-1]->win+=1;
                team[a-1]->score+=1;
                team[a-1]->lose+=1;
            }
            else{
                team[a-1]->score+=1;
                team[b-1]->score+=1;
            }
        }
        qsort(team,n,sizeof(team[0]),cmp);
        for(int i=0;i<n-1;i++)
        {
            printf("%d ",team[i]->teamnum);
        }
        printf("%d\n",team[n-1]->teamnum);

    }
}
