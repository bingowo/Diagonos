#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char xuehao[12];
    int chengji;
}xuesheng;
int cmp(const void *a,const void *b)
{
    int cja=((xuesheng*)a)->chengji,cjb=((xuesheng*)b)->chengji;
    if(cja!=cjb)return cjb-cja;
    else return strcmp(((xuesheng*)a)->xuehao,((xuesheng*)b)->xuehao);
}
int main()
{
    int T,n;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        int N,M,G;
        scanf("%d %d %d",&N,&M,&G);
        int score[M];
        int i,num=0;
        for(i=0;i<M;i++)
        {
            scanf("%d",&score[i]);
        }
        xuesheng xs[N];
        for(i=0;i<N;i++)
        {
            int j,k,ti,sum=0;
            scanf("%s %d",xs[i].xuehao,&j);
            for(k=0;k<j;k++)
            {
                scanf("%d",&ti);
                sum+=score[ti-1];
            }
            xs[i].chengji=sum;
        }
        qsort(xs,N,sizeof(xs[0]),cmp);
        for(i=0;i<M;i++)
        {
            if(xs[i].chengji>=G)num++;
            else break;
        }
        printf("case #%d:\n%d\n",n,num);
        for(i=0;i<num;i++)
        {
            printf("%s %d\n",xs[i].xuehao,xs[i].chengji);
        }
    }
    return 0;
}
