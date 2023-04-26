#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

typedef struct data
{
    int score;
    int win;
    int lose;
    int number;
} Data;

int
main()
{
    int n,m;
    int a,b,c;
    
    scanf("%d%d",&n,&m);
    while (n!=0 && m!=0)
    {
        Data *pdata = (Data*)malloc(n*sizeof(Data));
        for (int i=0; i<n; i++)
        {
            (pdata+i)->number = i+1;
            (pdata+i)->score = 0;
            (pdata+i)->win = 0;
            (pdata+i)->lose = 0;
        }
        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            switch (c)
            {
                case (1):
                    (pdata+a-1)->score += 3;
                    (pdata+b-1)->score -= 1;
                    (pdata+a-1)->win += 1;
                    (pdata+b-1)->lose += 1;
                    break;
                case (-1):
                    (pdata+a-1)->score -= 1;
                    (pdata+b-1)->score += 3;
                    (pdata+a-1)->lose += 1;
                    (pdata+b-1)->win += 1;
                    break;
                case (0):
                    (pdata+a-1)->score += 1;
                    (pdata+b-1)->score -= 1;
                    break;
            }
        }
        qsort(pdata, n, sizeof(Data), cmp);
        for (int i=0; i<n; i++)
        {
            printf("%d ",(pdata+i)->number);
        }
        printf("\n");
        scanf("%d%d",&n,&m);
    }
    
    return 0;
}


int
cmp(const void*a,const void* b)
{
    Data *pdata1 = (Data*)a;
    Data *pdata2 = (Data*)b;
    
    if (pdata1->score < pdata2->score)
    {
        return 1;
    }
    else if (pdata1->score == pdata2->score)
    {
        if (pdata1->win < pdata2->win)
        {
            return 1;
        }
        else if (pdata1->win == pdata2->win)
        {
            if (pdata1->lose > pdata2->lose)
            {
                return 1;
            }
            else if (pdata1->lose == pdata2->lose)
            {
                if (pdata1->number > pdata2->number)
                {
                    return 1;
                }
            }
        }
    }
    return -1;
}