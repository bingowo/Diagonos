#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char number[11];
    int sum;
}Student;
Student student[500];
int cmp(const void *a,const void *b)
{
    if((*(Student*)a).sum != (*(Student*)b).sum)
        return (*(Student*)a).sum<(*(Student*)b).sum;
    else
        return strcmp((*(Student*)a).number,(*(Student*)b).number);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        for(int i=0;i<500;i++)
        student[i].sum=0;
        int score[11]={0};
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        int pass=0;
        for(int j=0;j<M;j++)
        {
            scanf("%d",&score[j]);
        }
        for(int j=0;j<N;j++)
        {
            scanf("%s",student[j].number);
            char a;
            int s;
            scanf("%d",&s);
            if(s==0)
                student[j].sum=0;
            while((a=getchar())!='\n')
            {
                int anum=a-'0'-1;
                student[j].sum+=score[anum];
            }
        }
    qsort(student,N,sizeof(Student),cmp);
    for(int j=0;j<N;j++)
    {
        if(student[j].sum>=G)
            pass++;
    }
    printf("case #%d:\n",i);
    if(pass==0 && i==pass-1)
        printf("%d",pass);
    else
    {
            printf("%d\n",pass);
        for(int j=0;j<pass;j++)
            printf("%s %d\n",student[j].number,student[j].sum);
    }
    for(int j=0;j<11;j++)
        score[j]=0;
    } 
    return 0;
}
