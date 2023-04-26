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
    if(p1->score==p2->score&&p1->win==p2->win&&p1->lose==p2->lose)
        return p1->number-p2->number;
    if(p1->score==p2->score&&p1->win==p2->win)
        return p1->lose-p2->lose;
    if(p1->score==p2->score)
        return p2->win-p1->win;
    return p2->score-p1->score;
}
void function(int n,int m)
{
    if(n==0||m==0) return 0;
    team t[n];
    for(int i=0;i<n;i++)
    {
        t[i].number=i+1;
        t[i].score=0;
        t[i].win=0;
        t[i].lose=0;
    }
    int game[m][3];
    for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&game[i][0],&game[i][1],&game[i][2]);
            if(game[i][2]==1)
            {
                t[game[i][0]-1].win++;
                t[game[i][1]-1].lose++;
                t[game[i][0]-1].score+=3;
                t[game[i][1]-1].score--;
            }
            if(game[i][2]==-1)
            {
                t[game[i][0]-1].lose++;
                t[game[i][1]-1].win++;
                t[game[i][0]-1].score--;
                t[game[i][1]-1].score+=3;
            }
            if(game[i][2]==0)
            {
                t[game[i][0]-1].score++;
                t[game[i][1]-1].score++;
            }
        }
    qsort(t,n,sizeof(t[0]),cmp);
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",t[i].number);
    }
    printf("%d\n",t[n-1].number);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n!=0&&m!=0)
        function(n,m);
    return 0;
}
