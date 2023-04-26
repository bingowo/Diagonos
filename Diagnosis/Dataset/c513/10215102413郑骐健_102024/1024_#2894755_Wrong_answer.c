#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char num[12];
    int score;
}stu;

int cmp (const void*p1,const void *p2)
{
    stu*p_1 = (stu*)p1;
    stu*p_2 = (stu*)p2;
    if(p_1 ->score<p_2->score)return 1;
    else if(p_1 ->score == p_2->score)return strcmp(p_1->num,p_2->num);
    else return 0;
}
int main()
{
    int t;

    scanf("%d",&t);
    for(int i = 0;i < t ;i++)
    {    int out_num = 0;
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        int a[15];
        for(int z = 1;z < M+1;z++ )
        {
            scanf("%d",&a[z]);
        }
        stu All[500];
        for(int g = 0;g < N;g++)
        {
            scanf("%s",All[g].num);
            All[g].score = 0;
            int n;scanf("%d",&n);
            for(int t = 0; t< n;t++)
            {
                int p;
                scanf("%d",&p);
                All[g].score +=a[p];
            }
            if(All[g].score>=G)out_num+=1;
        }
        qsort(All,N,sizeof(stu),cmp);
        printf("case #%d:\n",i);
        if(out_num == 0)printf("0\n");
         for(int o = 0; o <out_num;o++)
         {
             printf("%s %d\n",All[o].num,All[o].score);
         }

    }
    return 0;
}
