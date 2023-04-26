#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int score;
    int win;
    int lose;
    int num;
} count;

int cmp(const void *q1,const void *q2)
{
    count *p1=(count *)q1;
    count *p2=(count *)q2;

    if(p1->score>p2->score) return -1;
    else if(p1->score<p2->score) return 1;

    if(p1->win>p2->win) return -1;
    else if(p1->win<p2->win) return 1;

    if(p1->lose<p2->lose) return -1;
    else if(p1->lose>p2->lose) return 1;

    if(p1->num<p2->num) return -1;
    else return 1;

}

int main()
{
    int m,n;
    count team[11]= {0};
    int a[2010],b[2010],c[2010];
    
    

    while(scanf("%d %d\n",&n,&m))
    {
        if(n==0&&m==0) break;
        
        for(int i=1; i<=n; i++)
            team[i].num=i;
            
        for(int j=0; j<m; j++)
        {
            scanf("%d %d %d\n",&a[j],&b[j],&c[j]);
            if(c[j]==1)
            {
                team[a[j]].score+=3;
                team[b[j]].score-=1;
                team[a[j]].win++;
                team[b[j]].lose++;
            }
            else if(c[j]==(-1))
            {
                team[a[j]].score-=1;
                team[b[j]].score+=3;
                team[a[j]].lose++;
                team[b[j]].win++;
            }
            else if(c[j]==0)
            {
                team[a[j]].score++;
                team[b[j]].score++;
            }
        }

        qsort(team+1,n,sizeof(team[1]),cmp);

        for(int k=1; k<=n; k++)
            printf("%d ",team[k].num);
        printf("\n");
    }
    return 0;
}