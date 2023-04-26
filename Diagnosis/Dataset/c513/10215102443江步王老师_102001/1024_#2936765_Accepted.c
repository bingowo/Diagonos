#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct s
{
    char index[12];
    int sum;
}info;

int cmp(const void *_a,const void *_b);

int main()
{
    int T,N,M,G;
    int i,j,k;
    scanf("%d",&T);
    
    for (i=0;i<T;i++)
    {
        scanf("%d %d %d",&N,&M,&G);
        info *student = (info *)malloc(sizeof(info)*N);
        int *score = (int *)malloc(sizeof(int)*(M+1));
        int r_ans,q;
        
        //存入每道题目的分数
        for (j=1;j<=M;j++)
        {
            scanf("%d",score+j);
        }
        
        //读入每个学生的信息
        for (j=0;j<N;j++)
        {
            r_ans=0;
            student[j].sum=0;
            scanf("%s",student[j].index);
            scanf("%d",&r_ans);
            for (k=0;k<r_ans;k++)
            {
                scanf("%d",&q);
                student[j].sum+=score[q];
            }
        }

        //进行排序
        qsort(student,N,sizeof(info),cmp);

        //输出部分
        printf("case #%d:\n",i);
        
        int num=0;
        
        for (j=0;j<N;j++)
        {
            if (student[j].sum >= G)
                num++;
            else
                break;
        }

        printf("%d\n",num);

        for (j=0;j<num;j++)
        {
            printf("%s %d\n",student[j].index,student[j].sum);
        }
        
    }
    return 0;
}


int cmp(const void *_a,const void *_b)
{
    info *a = (info *)_a;
    info *b = (info *)_b;
    
    if ((*a).sum < (*b).sum)
    {
        return 1;
    }
    else if ((*a).sum == (*b).sum && strcmp((*b).index,(*a).index) < 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}