#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char id[12];
    long long grades;
    int flag;
};

int cmp(const void* a,const void* b)
{
    struct student* x=(struct student*)a;
    struct student* y=(struct student*)b;
    if(x->flag==1&&y->flag==1)
    {
        if(x->grades==y->grades)
        {
            return strcmp(x->id,y->id);
        }
        return y->grades-x->grades;
    }
    else
    {
        return y->flag-x->flag;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,M;
        long long G;
        int jige=0;
        scanf("%d %d",&N,&M);
        scanf("%lld",&G);
        long long score[11]={0};
        struct student ans[501];
        for(int j=1;j<M+1;j++)
        {
            scanf("%lld",&score[j]);
        }
        for(int j=0;j<N;j++)
        {
            ans[j].grades=0;
            ans[j].flag=0;
        }
        for(int j=0;j<N;j++)
        {
            scanf("%s",ans[j].id);
            int num;
            scanf("%d",&num);
            for(int k=0;k<num;k++)
            {
                long long temp;
                scanf("%lld",&temp);
                ans[j].grades=ans[j].grades+score[temp];
            }
            if(ans[j].grades>=G)
            {
                ans[j].flag=1;
                jige++;
            }
        }
        qsort(ans,N,sizeof(ans[0]),cmp);
        printf("case #%d:\n%d\n",i,jige);
        for(int j=0;j<jige;j++)
        {
            printf("%s %lld\n",ans[j].id,ans[j].grades);
        }
    }
}
