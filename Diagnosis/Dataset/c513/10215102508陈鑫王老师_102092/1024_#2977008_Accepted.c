#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char num[12];
    int s;
}stu;
int cmp(const void*a,const void*b)
{
    stu *x=(stu*)a;
    stu *y=(stu*)b;
    if(x->s!=y->s)return y->s-x->s;
    else return strcmp(x->num,y->num);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,M,G,number=0;

        scanf("%d %d %d",&N,&M,&G);
        int score[M];
        stu student[N];
        for(int j=0;j<M;j++)
        {
            scanf("%d",&score[j]);
        }
        for(int j=0;j<N;j++)
        {
            int time,s1=0;
            scanf("%s %d",student[j].num,&time);
            for(int t=0;t<time;t++)
            {
                int m;
                scanf("%d",&m);
                s1+=score[m-1];
            }
            if(s1>=G)number+=1;
            student[j].s=s1;
        }
        printf("case #%d:\n",i);
        printf("%d\n",number);
        qsort(student,N,sizeof(stu),cmp);
        for(int h=0;h<N;h++)
        {
            if(student[h].s>=G)
            {
                printf("%s %d\n",student[h].num,student[h].s);
            }
        }

    }
    return 0;
}
