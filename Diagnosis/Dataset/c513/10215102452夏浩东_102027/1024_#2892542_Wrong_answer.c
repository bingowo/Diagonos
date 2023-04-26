#include <stdio.h>
#include <stdlib.h>
struct std{
  char num[12];
  int score;
  int win;
};
int cmp(const void *a,const void *b)
{
    struct std *A=(struct std*)a;
    struct std *B=(struct std*)b;
    int res=0;
    if(A->score != B->score) res = B->score > A->score ? 1:-1;
    else
    {
        for(int i=0;i<12;i++)
        {
            if(A->num[i] != B->num[i])
            {
                res = A->num[i] > B->num[i] ? 1:-1;
                break;
            }
        }
    }
    return res;
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int N=0,M=0,G=0;
        scanf("%d %d %d",&N,&M,&G);
        int *L=(int*)malloc(M*sizeof(int));
        struct std* SL = (struct std*)malloc(N*sizeof(struct std*));
        for(int k=0;k<M;k++)
        {
            scanf("%d",&L[k]);
        }
        for(int k=0;k<N;k++)
        {
            scanf("%s %d",SL[k].num,&SL[k].win);
            for(int j=0;j<SL[k].win;j++)
            {
                int sco=0;
                scanf("%d",&sco);
                SL[k].score+=L[sco-1];
            }
        }
        qsort(SL,N,sizeof(struct std),cmp);
        printf("case #%d:\n",i);
        for(int t=0;t<N;t++)
        {
            if(SL[t].score>G)
            {
                printf("%d\n",N-t-1);
                break;
            }
        }
        for(int t=0;t<N;t++)
        {
            printf("%s %d\n",SL[t].num,SL[t].score);
        }
    }
    return 0;
}