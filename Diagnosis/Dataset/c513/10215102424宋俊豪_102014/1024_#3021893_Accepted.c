#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[12];//学号
    int sum;//分数
}Stu;

int cmp(const void *a,const void *b)
{
    const Stu *x=a,*y=b;
    if(x->sum==y->sum)
    {
        return strcmp(x->name,y->name);
    }
    else
    {return (y->sum-x->sum);}
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int N,M,G,num,que;
        scanf("%d %d %d",&N,&M,&G);//输入学生个数、题目书、分数线
        int score[11];//每道题对应的分数
        int cnt=0;Stu stus[500];

        for(j=1;j<=M;j++)
        {
            scanf("%d",&score[j]);//每道题对应的分数
        }
        for(j=0;j<N;j++)//计算每个学生的分数
        {
            scanf("%s",stus[j].name);//输入学生学号
            stus[j].sum=0;
            scanf("%d",&num);//做出的题目数量
            for(k=0;k<num;k++)
            {
                scanf("%d",&que);
                stus[j].sum+=score[que];
            }
                if(stus[j].sum>=G)
                {
                    cnt++;
                }
        }
        qsort(stus,N,sizeof(Stu),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
        for(j=0;j<cnt;j++)
        {
            printf("%s %d\n",stus[j].name,stus[j].sum);
        }
        }
        return 0;
}
