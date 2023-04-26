#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu_info
{
    char name[12];
    int score;
};

int cmp(const void* p1, const void* p2)
{
    struct stu_info* a = (struct stu_info*)p1;
    struct stu_info* b = (struct stu_info*)p2;
    if(a->score != b->score)
        return b->score - a->score;
    else
    {
        if(strcmp(a->name,b->name) > 0)  return 1;
        else  return -1;
    }

}

int main(void)
{
    int T,N,M,G,S;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {   
        int score[10];
        int count=0;
        struct stu_info stu_list[500];
        scanf("%d%d%d",&N,&M,&G);

        for(int j=0;j<M;j++)
            scanf("%d",&score[j]);

        for(int j=0;j<N;j++)
        {   
            int k=0;
            while(( stu_list[j].name[k++] = getchar())!= ' ' ){}stu_list[j].name[11]='\0';
            scanf("%d",&S);
            for(int m=0;m<S;m++)
            {
                int n;
                scanf("%d",&n);
                stu_list[j].score += score[n-1];
            }
            if(stu_list[j].score >= G)count++;
        }
        qsort(stu_list,N,sizeof(struct stu_info),cmp);
        printf("case #%d:\n%d\n",i,count);
        for (int j = 0; j < count; j++)
        {
            printf("%s %d\n",stu_list[j].name,stu_list[j].score);
        }
    }
    system("pause");
    return 0;
}