#include<stdio.h>
#include<stdlib.h>

struct group
{
    int id;
    int win;
    int lose;
    int score;
};

int cmp(const void* a,const void* b)
{
    struct group* x=(struct group*) a;
    struct group* y=(struct group*) b;
    if(x->score==y->score)
    {
        if(x->win==y->win)
        {
            if(x->lose==y->lose)
            {
                return (x->id-y->id);
            }
            return (x->lose-y->lose);
        }
        return (y->win-x->win);
    }
     return (y->score-x->score);
}



int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(m==0&&n==0)
        {
            return 0;
        }
        struct group ans[11];
        for(int i=0;i<n;i++)
        {
            ans[i].id=i+1;
            ans[i].win=0;
            ans[i].lose=0;
            ans[i].score=0;
        }
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                ans[a-1].score+=3;
                ans[a-1].win++;
                ans[b-1].score-=1;
                ans[b-1].lose++;
            }
            else if(c==-1)
            {
                ans[b-1].score+=3;
                ans[a-1].score-=1;
                ans[b-1].win++;
                ans[a-1].lose++;
            }
            else
            {
                ans[a-1].score++;
                ans[b-1].score++;
            }
        }
        qsort(ans,n,sizeof(ans[0]),cmp);
        for(int i=0;i<n-1;i++)
        {
            printf("%d ",ans[i].id);
        }
        printf("%d\n",ans[n-1].id);
    }
    return 0;
}
