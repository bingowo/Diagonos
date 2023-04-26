#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int sc;
    char id[12];
}stu;

int cmp(const void *_a,const void *_b)
{
    stu const *a = (stu const *)_a;
    stu const *b = (stu const *)_b;
    if(a->sc==b->sc)
        return strcmp(a->id, b->id);
    return b->sc-a->sc;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,M,G;
        scanf("%d %d %d",&N,&M,&G);
        int p[11];
        for(int j=1;j<=M;j++)
            scanf("%d",&p[j]);
        stu stds[501];
        for(int j=0;j<N;j++)
        {
            int a;
            stds[j].sc=0;
            scanf("%s %d",stds[j].id,&a);
            for(int k=0;k<a;k++)
            {
                int slv;
                scanf("%d",&slv);
                stds[j].sc+=p[slv];
            }
        }
        qsort(stds,N,sizeof(stu),cmp);
        int ps=0;
        while(stds[ps].sc>=G)
            ps++;
        printf("case #%i:\n%i\n", i, ps);
        for(int j=0;j<ps;j++)
            printf("%s %i\n", stds[j].id, stds[j].sc);
    }
    return 0;
}
