#include <stdio.h>
#include <stdlib.h>
struct bisai
{
    int number;int score;int win;int lose
};

int cmp(const void *a,const void *b)
{
    struct bisai* ap=(struct bisai *)a;
    struct bisai* bp=(struct bisai *)b;
    if((*ap).score!=(*bp).score)
        return (bp->score-ap->score);
    else
    {
        if(ap->win!=bp->win)
            return (bp->win-ap->win);
        else
        {
            if(ap->lose!=bp->lose)
                return (ap->lose-bp->lose);
            else
                return (ap->number-bp->number);
        }
    }
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)//n代表球队数量，m代表比赛场数
    {
        if(n==0);
        else
        {
            struct bisai a[n];
            int s[m][3];
            int i,j;
            for(i=0;i<m;i++)
            {
                for(j=0;j<3;j++)
                    scanf("%d",&s[i][j]);
            }
            for(i=0;i<n;i++)
            {
                a[i].number=i+1;
                a[i].score=0;
                a[i].win=0;
                a[i].lose=0;
            }
            for(i=0;i<m;i++)
            {
                if(s[i][2]==1)
                {
                    a[s[i][0]-1].score=a[s[i][0]-1].score+3;a[s[i][0]-1].win=a[s[i][0]-1].win+1;
                    a[s[i][1]-1].score=a[s[i][1]-1].score-1;a[s[i][1]-1].lose=a[s[i][1]-1].lose+1;
                }
                else
                {
                    if(s[i][2]==0)
                    {
                        a[s[i][0]-1].score=a[s[i][0]-1].score+1;
                        a[s[i][1]-1].score=a[s[i][1]-1].score+1;
                    }
                    else
                    {
                        a[s[i][0]-1].score=a[s[i][0]-1].score-1;a[s[i][0]-1].lose=a[s[i][0]-1].lose+1;
                        a[s[i][1]-1].score=a[s[i][1]-1].score+3;a[s[i][1]-1].win=a[s[i][1]-1].win+1;
                    }
                }
            }
            qsort(a,n,4*sizeof(int),cmp);
            for(i=0;i<n;i++)
                printf("%d ",a[i].number);
            printf("\n");
        }
    }
}

