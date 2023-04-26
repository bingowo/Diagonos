#include <stdio.h>
#include <stdlib.h>

typedef struct STUDENT
{
    char id[11];//学号
    int S;//对的题数
    int num[10];//题号
    int s;//总分
}stu;

int cmp(const void*_a, const void*_b)
{
    stu* a=(stu*)a;
    stu* b=(stu*)b;
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
        int N,M,G;//学生人数N，题目数M，分数线G
        int score[10];
        scanf("%d %d %d",&N,&M,&G);
        for(int j=0;j<M;j++) scanf("%d",&score[j]);
        for(int n=0;n<N;n++) scanf("%s %d %s",a[n].id,&a[n].S,a[n].num);

        int pass_num=0;
        for(int n=0;n<N;n++)
        {
            for(int m=0;m<a[n].S;m++) a[n].s=a[n].s+score[a[n].num[m]-1];
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
