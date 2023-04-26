#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long long num[51];
    int cnt;
}line;

int cmp(const void* a, const void* b)
{
    line m = *(line*)a, n = *(line*)b;
    int i = 0;
    while(m.num[i]!=-1 && n.num[i]!=-1)
    {
        if(m.num[i] > n.num[i])
            return -1;
        if(m.num[i] < n.num[i])
            return 1;
        i++;
    }
    return n.cnt - m.cnt;
}

int main()
{
    int T, N, i, j, k;
    int t;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &N);
        line ln[N];
        for(j=0; j<N; j++)
        {
            ln[j].cnt = 0;
            for(t=0; t<51; t++)
            {
                ln[j].num[t] = 0;
                scanf("%lld", &ln[j].num[t]);
                if(ln[j].num[t] == -1)
                    break;
                ln[j].cnt++;
            }
        }

        qsort(ln,N,sizeof(ln[0]),cmp);
        for(j=0; j<N; j++)
        {
            for(k=0; k<=ln[j].cnt; k++)
            {
                if(k == ln[j].cnt)
                {
                    printf("\n");
                    break;
                }
                printf("%d ", ln[j].num[k]);
            }
        }
        
    }

    return 0;
}
