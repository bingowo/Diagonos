#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char number[12];
    int score;
}STU;
int cmp(const void*a,const void*b)
{
    STU*st1,*st2;
    st1 = (STU*)a,st2 = (STU*)b;
    if(st1->score != st2->score)
        return st2->score - st1->score;
    else
        return strcmp(st1->number,st2->number);
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int j,count = 0;
        int N,M,G;
        STU student[N];
        STU student_pass[N];
        scanf("%d %d %d",&N,&M,&G);
        int question[M];
        for(j = 0;j < M;j++)
            scanf("%d",&question[j]);
        for(j = 0;j < N;j++)
        {
            int S,k;
            scanf("%s %d",student[j].number,&S);
            int solution[S];
            student[j].score = 0;
            for(k = 0;k < S;k++)
            {
                scanf("%d",&solution[k]);
                student[j].score += question[solution[k] - 1];
            }
            if(student[j].score >= G)
            {
                student_pass[count] = student[j];
                count++;
            }
        }
        qsort(student_pass,count,sizeof(student_pass[0]),cmp);
        printf("case #%d:\n%d\n",i,count);
        for(j = 0;j < count;j++)
        {
            printf("%s %d",student_pass[j].number,student_pass[j].score);
        }
    }
    return 0;
}
