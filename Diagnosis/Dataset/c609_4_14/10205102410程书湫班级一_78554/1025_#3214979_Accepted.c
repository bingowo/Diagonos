#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct board
{
    int score;
    int No;
    int wins;
    int negative;
};
int cmp(const void *a,const void *b)
{
    struct board p1,p2;
    p1=*(struct board *)a;
    p2=*(struct board *)b;
    if(p1.score==p2.score)
    {
        if(p1.wins==p2.wins)
        {
            if(p1.negative==p2.negative)
                return p1.No-p2.No;
            else
                return p1.negative-p2.negative;
        }
        else
            return p2.wins-p1.wins;
    }
    else
        return p2.score-p1.score;
}
int main()
{
    int N,M,i;
    struct board team[11];
    while(scanf("%d%d",&N,&M)&&(N!=0||M!=0))
    {
        for(i=0;i<11;i++)
        {
            team[i].score=0;
            team[i].wins=0;
            team[i].negative=0;
            team[i].No=i;
        }
        int a,b,c;
        for(int i=1;i<=M;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c==1)
            {
                team[a].score+=3;
                team[a].wins++;
                team[b].score-=1;
                team[b].negative++;
            }
            else if(c==-1)
            {
                team[b].score+=3;
                team[b].wins++;
                team[a].score-=1;
                team[a].negative++;
            }
            else if(c==0)
            {
                team[a].score+=1;
                team[b].score+=1;
            }
        }
        qsort(&team[1],N,sizeof(team[0]),cmp);
        for(i=1;i<=N;i++) printf("%d%c",team[i].No,(i==N?'\n':' '));
    }
    return 0;
}
