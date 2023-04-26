#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int score;
    int wint;
    int lost;
    int num;
}team;

int cmp(const void* a, const void* b)
{
    team m = *(team*)a, n = *(team*)b;
    if(m.score!=n.score)
        return m.score-n.score;
    if(m.wint!=n.wint)
        return m.wint-n.wint;
    if(m.lost!=n.lost)
        return n.lost-m.lost;

    return n.num-m.num;
}

int main()
{
    int n, m, a, b, c, i;
    scanf("%d%d",&n, &m);
    while(m!=0||n!=0)
    {
        team tm[n];
        for(i=0; i<n; i++)
        {
            tm[i].score = 0;
            tm[i].wint = 0;
            tm[i].lost = 0;
            tm[i].num = 0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a, &b, &c);
            tm[a].num = a;
            tm[b].num = n;
            if(c==1)
            {
                tm[a].score += 3;
                tm[b].score -= 1;
                tm[a].wint++;
                tm[b].lost++;
            }
            if(c==-1)
            {
                tm[b].score += 3;
                tm[a].score -= 1;
                tm[b].wint++;
                tm[a].lost++;
            }
            if(c==0)
            {
                tm[a].score++;
                tm[b].score++;
            }
        }

        qsort(tm,n,sizeof(tm[0]),cmp);

        for(i=0; i<=n; i++)
        {
            if(i==n)
            {
                printf("\n");
                break;
            }
            printf("%d", tm[i].num);
            if(i!=n-1)
                printf(" ");
        }
        scanf("%d%d",&n, &m);
    }

    return 0;
}
