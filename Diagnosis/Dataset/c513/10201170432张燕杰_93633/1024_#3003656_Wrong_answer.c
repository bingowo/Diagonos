#include<stdio.h>
#include<stdlib.h>


typedef struct stu{
    long long int num;
    int mark;
}stu;

int cmp(const void*a,const void*b)
{
    stu*p1 = (stu*)a;
    stu*p2 = (stu*)b;
    if(p1->mark>p2->mark)
    {
        return -1;
    }
    else if(p1->mark<p2->mark)
    {
        return 1;
    }
    else{
        if(p1->num>p2->num)
        {
            return 1;
        }
        else if(p1->num<p2->num)
        {
            return -1;
        }
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int N,M,G;                              //N为学生总数，M为考试题数，G为分数线
        scanf("%d %d %d\n",&N,&M,&G);
        stu* Stu = (stu*)malloc(sizeof(stu)*N);
        int*score = (int*)malloc(sizeof(int)*M);

        //每题分值赋值
        for(int j = 0;j<M;j++)
        {
            scanf("%d",score+j);
            getchar();
        }

        for(int j = 0;j<N;j++)
        {
            int q_sum;
            scanf("%lld %d",&((Stu+j)->num),&q_sum);

            (Stu+j)->mark = 0;
            for(int x = 0;x<q_sum;x++)
            {
                int temp;
                scanf("%d",&temp);
                //getchar();
                (Stu+j)->mark = (Stu+j)->mark+*(score+temp-1);
            }
        }
        qsort(Stu,N,sizeof(stu),cmp);

        int total = 0;
        for(int z = 0;z<N;z++)
        {
            if((Stu+z)->mark>=G)
            {
                total++;
            }
        }
        printf("case #%d:\n%d\n",i,total);
        for(int z = 0;z<N;z++)
        {
            if((Stu+z)->mark>=G)
            {
                printf("%lld %d\n",(Stu+z)->num,(Stu+z)->mark);
            }
            else
            {
                break;
            }
        }
        free(score);
        free(Stu);

    }
    return 0;
}