#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct SSS
{
    int score;
    int win;
    int fail;
    int number;
}sss;

int cmp(const void*_a,const void*_b)
{
    sss*a=(sss*)_a;
    sss*b=(sss*)_b;
    if(a->score != b->score) return b->score - a->score;
    else if(a->win != b->win) return b->win - a->win;
    else if(a->fail != b->fail) return a->fail - b->fail;
    else return a->number - b->number;
}
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0) break;
        int a,b,c;
        sss x[15];
        for(int i=0;i<15;i++)
        {
            x[i].score=0;
            x[i].number=i;
            x[i].fail=0;
            x[i].win=0;
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c==1)
            {
                x[a].score+=3;
                x[a].win+=1;
                x[b].score-=1;
                x[b].fail+=1;
            }
            else if(c==-1)
            {
                x[a].score-=1;
                x[a].fail+=1;
                x[b].score+=3;
                x[b].win+=1;
            }
            else if(c==0)
            {
                x[a].score+=1;
                x[b].score+=1;
            }
        }
        qsort(x+1,n,sizeof(x[0]),cmp);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",x[i].number);
        }
        printf("\n");
    }
    return 0;
}

