#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[10];
    int score;

}student;

int cmp(const void* a, const void* b)
{
    student A = *(student*)a;
    student B = *(student*)b;
    if(A.score != B.score)
    {
        return A.score < B.score;
    }
    else
    {
        return strcmp(A.s,B.s);
    }
}


int main()
{
    int T1;
    int T2;
    int qn;
    int jg;
    int sum;
    int zqn;//正确题目数
    int zq[100];//正确题目
    student s1[1000];
    int qc[100];//题目分值
    scanf("%d",&T1);
    for(int i = 0; i < T1; i++)
    {
        scanf("%d",&T2);
        scanf("%d",&qn);
        scanf("%d",&jg);
        for(int k = 0; k < qn;k++)
            {
                scanf("%d",&qc[k]);
            }
        for(int j = 0;j < T2;j++)
        {
            scanf("%s",s1[j].s);
            s1[j].score = 0;
            scanf("%d",&zqn);
            for(int k = 0; k < zqn;k++)
            {
                scanf("%d",&zq[k]);
                s1[j].score += qc[zq[k] - 1];
            }

        }
        qsort(s1,T2,sizeof(s1[0]),cmp);
        sum = 0;
        for(int j = 0; j < T2;j++)
        {
            if(s1[j].score >= jg)
            {
                sum++;
            }
            else
            {
                break;
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",sum);
        for(int j = 0; j < sum;j++)
        {
            printf("%s %d\n",s1[j].s,s1[j].score);
        }
    }
    return 0;
}
