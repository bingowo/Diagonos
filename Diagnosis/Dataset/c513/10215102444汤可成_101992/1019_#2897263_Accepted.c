#include <stdio.h>
#include <stdlib.h>

typedef struct team
{
    int t;
    int sco;
    int win;
    int lose;
}team;

int cmp(const void* a, const void* b)
{
    team* pa = (team*)a;
    team* pb = (team*)b;
    if(pa->sco > pb->sco) return -1;
    else if(pa->sco < pb->sco) return 1;
    else
    {
        if(pa->win > pb->win) return -1;
        else if(pa->win < pb->win) return 1;
        else
        {
            if(pa->lose < pb->lose) return -1;
            else if(pa->lose > pb->lose) return 1;
            else
            {
                if(pa->t < pb->t) return -1;
                else return 1;
            }
        }
    }
}

int main()
{
    int n = 0;
    int m = 0;
    while (scanf("%d %d",&n, &m))
    {
        team s[10] = {0};
        if(n==0 && m==0)break;
        int i = 0;
        for(i = 0; i < n; i++)
        {
            s[i].t = i+1;
        }
        for (i = 0; i < m; i++)
        {
            int n1 = 0;
            int n2 = 0;
            int n = 0;
            scanf("%d %d %d", &n1, &n2, &n);
            if(n == 1)
            {
                s[n1-1].sco+=3;
                s[n2-1].sco--;
                s[n1-1].win++;
                s[n2-1].lose++;
            }
            else if(n == -1)
            {
                s[n1-1].sco--;
                s[n2-1].sco+=3;
                s[n1-1].lose++;
                s[n2-1].win++;
            }
            else
            {
                s[n1-1].sco++;
                s[n2-1].sco++;
            }
        }
        qsort(s, n, sizeof(s[0]), cmp);
        for(i = 0; i < n; i++)
        {
            printf("%d ",s[i].t);
        }
        printf("\n");
    }
    return 0;
}
