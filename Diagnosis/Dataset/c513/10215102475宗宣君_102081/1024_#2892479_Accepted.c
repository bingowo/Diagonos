#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
char number[12];
int score;
}ans;
int cmp(const void* a,const void* b)
{
    int m,n;
    m = (*(ans*)a).score;n = (*(ans*)b).score;
    if(m<n) return 1;
    else if(m==n&&strcmp((*(ans*)a).number,(*(ans*)b).number)>0) return 1;
    else return -1;
}
int main()
{
    int T,i,j,k,m;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int N,M,G,sum = 0;
        scanf("%d %d %d",&N,&M,&G);
        int res[M];
        for(j = 0;j<M;j++)
        {
            scanf("%d",&res[j]);
        }
        ans b[N];
        for(k = 0;k<N;k++)
        {

            scanf("%s",b[k].number);
            int S;
            b[k].score = 0;
            scanf("%d",&S);
            int q[S];
            for(m = 0;m<S;m++)
            {
                scanf("%d",&q[m]);
                b[k].score = b[k].score + res[q[m]-1];
            }
            if(b[k].score>=G) sum++;
        }
        qsort(b,N,sizeof(ans),cmp);
        printf("case #%d:\n%d\n",i,sum);
        for(j=0;j<sum;j++)
            printf("%s %d\n",b[j].number,b[j].score);

    }
    return 0;
}
