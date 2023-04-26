#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct LInt{ long long num; int fnum;} L;

int cmp (const void * a, const void * b)
{
    if(*(L*)a.fnum != *(L*)b.fnum) return 1;
    else return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        int N;
       scanf("%d",&N);
        L* l = (L*)malloc(sizeof(L)*(N+1));
        for(int j = 0; j < N; j++)
        {
            long long tmp;
            scanf("%lld",&tmp);
            l[j].num = tmp;
            if(abs(tmp)<10) l[j].fnum = abs(tmp);
            else
            {
                while(abs(tmp)>=10) tmp/=10;
                l[j].fnum = abs(tmp);
            }
        }
        qsort(l,N,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(int j = 0; j < N; j++)
        {
            printf("%lld ",l[j].num);
        }
        printf("\n");
        free(l);
    }
    return 0;
}