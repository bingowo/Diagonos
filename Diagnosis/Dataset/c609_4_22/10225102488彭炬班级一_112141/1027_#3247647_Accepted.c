#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char number[12];
    int score;
}Stu;

int cmp(const void *a,const void *b)
{
    Stu *p1 = (Stu *)a;
    Stu *p2 = (Stu *)b;
    if(p1->score == p2->score)
        return strcmp(p1->number,p2->number);
    else
        return p2->score - p1->score;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++)
    {
        int  N,M,G;
        scanf("%d %d %d",&N,&M,&G);
        int point[10];
        for(int j = 0;j < M;j++)
            scanf("%d",&point[j]);
        Stu student[500];
        int len,count = 0;
        for(len = 0;len < N;len++)
        {
            student[len].score = 0;
            scanf("%s",&student[len].number);
            int num;
            scanf("%d",&num);
            for(int n = 0;n < num;n++)
            {
                int k;
                scanf("%d",&k);
                student[len].score += point[k-1];
            }
            if(student[len].score >= G)
                count++;
        }
        qsort(student,len,sizeof(student[0]),cmp);
        printf("case #%d:\n%d\n",i,count);
        for(int j = 0;j < count;j++)
            printf("%s %d\n",student[j].number,student[j].score);
    }
    return 0;
}
