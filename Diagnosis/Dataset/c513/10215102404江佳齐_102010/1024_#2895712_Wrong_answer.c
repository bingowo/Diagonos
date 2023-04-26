#include <stdio.h>
#include <stdlib.h>

typedef struct STUDENT
{
    char id[15];//学号
    int s;//总分
}stu;

int cmp(const void*_a, const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if((a->s)!=(b->s)) return ((b->s)-(a->s));
    else return((a->id)-(b->id));
}

int main()
{
    int T; //问题数
    scanf("%d",&T);
    stu a[500];
    for(int i=0;i<T;i++)
    {
        int N,M,G,X,S;//学生人数N，题目数M，分数线G
        int score[10];
        scanf("%d %d %d",&N,&M,&G);
        for(int j=0;j<M;j++) scanf("%d",&score[j]);
        int pass_num=0;
        for(int n=0;n<N;n++)
        {
            scanf("%s %d",a[n].id,&S);
            int ans=0;
            for(int m=0;m<S;m++)
            {
                scanf("%d",&X);
                ans=ans+score[X-1];
            }
            a[n].s=ans;
            if(a[n].s>G) pass_num++;
        }

        printf("case #%d:\n",i);
        printf("%d\n",pass_num);
        qsort(a,pass_num,sizeof(stu),cmp);
        for(int x=0;x<pass_num;x++)
            printf("%s %d\n",a[x].id,a[x].s);
    }
    return 0;
}
