#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char id[12];
    int S;
    int *num;       //这S道题目的题号
    int score;
}STUDENT;
int compar(const void *p1,const void *p2);
int main()
{
    int T,N,M,G,*Mscore,i,j,tim=0,num=0;
    scanf("%d",&T);
    while(tim<T)
    {
        scanf("%d %d %d",&N,&M,&G);
        Mscore=(int*)malloc(M*sizeof(int));         //题目的分值
        STUDENT* student=(STUDENT*)malloc(N*sizeof(STUDENT));
        //memset(student,0,sizeof(STUDENT));

        for(i=0;i<M;i++)
            scanf("%d",&Mscore[i]);
        for(i=0;i<N;i++)            //读入学生数据
        {
            scanf("%s",student[i].id);
            scanf("%d",&student[i].S);
            student[i].score=0;
            student[i].num=(int*)malloc(student[i].S*sizeof(int));
            for(j=0;j<student[i].S;j++)
                scanf("%d",&student[i].num[j]);
        }
        for(i=0;i<N;i++)        //计算学生分数
        {
            for(j=0;j<student[i].S;j++)
                student[i].score+=Mscore[student[i].num[j]-1];
        }
        qsort(student,N,sizeof(STUDENT),compar);

        printf("case #%d:\n",tim);
        for(i=0;i<N;i++)
        {
            if(student[i].score<G)
                break;
            else
            {
                num++;
            }
        }
        printf("%d\n",num);
        for(i=0;i<num;i++)
        {
            printf("%s %d\n",student[i].id,student[i].score);
        }

        free(Mscore);
        for(i=0;i<N;i++)
            free(student[i].num);
        free(student);
        tim++;
        num=0;
    }


    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    STUDENT *a,*b;
    a=(STUDENT*)p1;  b=(STUDENT*)p2;
    if(a->score>b->score)
        flag=-1;
    else if(a->score<b->score)
        flag=1;
    else
    {
        if(strcmp(a->id,b->id)<0)
            flag=-1;
        else
            flag=1;
    }
    return flag;
}
