#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char id[12];
    int num;
    int S[11];
    int score;
} student;
int cmp(const void* a,const void* b);
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int N,M,G,count=0;
        scanf("%d%d%d",&N,&M,&G);
        int subject[M];
        student students[N];
        for (int j=0;j<M;j++)
            scanf("%d",&subject[j]);
        for (int j=0;j<N;j++)
        {
            scanf("%s %d",students[j].id,&students[j].num);
            students[j].score=0;
            for (int k=0;k<students[j].num;k++)
            {
                scanf("%d",&students[j].S[k]);
                students[j].score+=subject[students[j].S[k]-1];
            }
            if (students[j].score>=G)
                count++;
        }
        student temp;
        for (int j=0;j<N-1;j++)
        {
            for (int k=N-1;k>j;k--)
            {
                if (students[k].score>students[k-1].score)
                {
                    temp=students[k];
                    students[k]=students[k-1];
                    students[k-1]=temp;
                }
                else if(students[k].score==students[k-1].score)
                {
                    if (strcmp(students[k].id,students[k-1].id)<0)
                    {
                        temp=students[k];
                        students[k]=students[k-1];
                        students[k-1]=temp;
                    }
                }
            }
        }
        printf("case #%d:\n%d\n",i,count);
        for (int j=0;j<count;j++)
        {
            printf("%s %d\n",students[j].id,students[j].score);    
        }
    }
    return 0;
}

