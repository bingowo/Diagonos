#include <stdio.h>
#include <stdlib.h>

struct stu
{
    long long int number;
    int score;
};

int cmp(const void *a,const void *b)
{
    struct stu* ap=(struct stu *)a;
    struct stu* bp=(struct stu *)b;
    if(ap->score!=bp->score)
        return (bp->score-ap->score);
    else
    {
        if(ap->number>bp->number)
            return 1;
        else
            return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int N,M,G;   //N是学生人数，M是考试题目数，G是分数线
        scanf("%d %d %d",&N,&M,&G);
        int a[100]={0};  //存储每一道题的分数;
        int j;
        for(j=0;j<M;j++)
            scanf("%d",&a[j]);
        struct stu b[N];//存储学生
        for(j=0;j<N;j++)
            b[j].score=0;
        for(j=0;j<N;j++)
        {
            scanf("%lld",&(b[j].number));
            int S;
            scanf("%d",&S);  //学生解出题目总个数
            int c[10]={0};
            int k;
            for(k=0;k<S;k++)
                scanf("%d ",&c[k]);
            for(k=0;k<S;k++)
            {
                b[j].score=b[j].score+a[c[k]-1];
            }
        }
        qsort(b,N,sizeof(struct stu),cmp);
        int l=0;
        for(j=0;j<N;j++)
            {
                if(b[j].score>=G)
                l=l+1;
            }
            printf("case #%d:\n",i);
            if(l==0)
                printf("0");
            else
            {
            printf("%d\n",l);
            for(j=0;j<N;j++)
            {
                if(b[j].score>=G)
                    printf("%lld %d\n",b[j].number,b[j].score);
            }
            }
    }

}
