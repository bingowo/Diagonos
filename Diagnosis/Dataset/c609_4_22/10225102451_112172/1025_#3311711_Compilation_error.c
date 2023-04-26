#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int num;
    int score;
    int win;
    int lose;
}TEAM;
void solve(TEAM *p,int a,int b,int c)
{
    if(c==1)
    {
        (p+a-1)->score+=3;
        (p+b-1)->score-=1;
        (p+a-1)->win+=1;
        (p+b-1)->lose+=1;
    }
    else if(c==-1)
    {
        (p+b-1)->score+=3;
        (p+a-1)->score-=1;
        (p+b-1)->win+=1;
        (p+a-1)->lose+=1;
    }
    else
    {
        (p+a-1)->score+=1;
        (p+b-1)->score+=1;
    }
}
int cmp(const void *p1,const void *p2)
{
    TEAM *a=(TEAM*)p1;
    TEAM *b=(TEAM*)p2;
    if(a->score==b->score)
    {
        if(a->win=b->win)
        {
            if(a->lose=b->lose)
                return a->num-b->num;
            return a->lose-b->lose;
        }
        return b->win-a->win;
    }
    return b->score-a->score;
}
int main()
{
    char c;
    while(1)
    {
        int n;
        scanf("%d",&n);
        if (n==0) break;
        TEAM *p=(int*)malloc(sizeof(TEAM)*(n));
        for(int i=0;i<n;i++)
        {
            (p+i)->num=i+1;
            (p+i)->score=0;
            (p+i)->win=0;
            (p+i)->lose=0;
        }
        int t;
        scanf("%d",&t);
        for(int i=0;i<t;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            solve(p,a,b,c);}
            qsort(p,n,sizeof(TEAM),cmp);
            for(int i=0;i<n-1;i++)
            {
                printf("%d ",(p+i)->num);
            }
            printf("%d\n",(p+n-1)->num);
    }
}
return 0;
}