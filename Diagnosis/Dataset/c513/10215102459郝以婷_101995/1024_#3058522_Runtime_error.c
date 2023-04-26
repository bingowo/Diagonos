#include <stdio.h>
#include <stdlib.h>

struct STU
{
    char s[11];
    int sco;
};

int cmp(const void *a,const void *b)
{
    struct STU *a1=( struct STU*)a;
    struct STU *b1=( struct STU*)b;
    if(a1->sco!=b1->sco)
        return b1->sco-a1->sco;
    else
        return strcmp(a1->s,b1->s);
}

int main()
{

    int T,i,N,M,G,j,m,test,count0,k,count1;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        count1=0;
        scanf("%d %d %d",&N,&M,&G);
        struct STU stu[N+1];
        int score[M+1];
        for(j=1;j<=M;j++)
        {
            scanf("%d",&score[j]);
        }
        for(j=0;j<N;j++)
        {
            count0=0;
            scanf("%s %d",stu[j].s,&m);
            for(k=0;k<m;k++)
            {
                scanf("%d",&test);
                count0=count0+score[test];
            }
            if(count0>=G)
            {
                stu[j].sco=count0;
                count1++;
            }
            else
                j--;
        }
        qsort(stu,count1,sizeof(struct STU),cmp);
        printf("case #%d:\n",i);
        printf("%d]n",count1);
        for(j=0;j<count1;j++)
        {
            printf("%s %d\n",stu->s,stu->sco);
        }
    }
    return 0;
}
