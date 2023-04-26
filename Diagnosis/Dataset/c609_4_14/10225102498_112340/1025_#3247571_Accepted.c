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
    if(m.score!= n.score)
        return n.score-m.score;
    if(m.wint != n.wint)
        return n.wint-m.wint;
    if(m.lost != n.lost)
        return m.lost-n.lost;

    return m.num-n.num;
}

int main()
{
    int n, m, a;
    int b, c, i;
    scanf("%d%d",&n, &m);
    while(m!=0||n!=0)
    {
        team tm[n];
        for(i=0; i<n; i++)
        {
            tm[i].score = 0;
            tm[i].wint = 0;
            tm[i].lost = 0;
            tm[i].num = i+1;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a, &b, &c);
            a--;
            b--;

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
