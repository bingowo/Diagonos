#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a ,const void* b);

typedef struct data
{
    char stuid[12];
    int grade;
} Data;

int
main()
{
    int questions;
    int N,M,G;
    int answers;
    int temp;
    int count = 0;

    scanf("%d",&questions);
    for (int i=0;i<questions;i++)
    {
        count =0;
        scanf("%d%d%d",&N,&M,&G);
        Data *pdata = (Data*)malloc(N*sizeof(Data));
        int *pgrade = (int*)malloc(M*sizeof(int));
        for (int j=0;j<M;j++)
        {
            scanf("%d",pgrade+j);
        }
        for (int j=0;j<N;j++)
        {
            scanf("%s",(pdata+j)->stuid);
            (pdata+j)->stuid[16] = '\0';
            (pdata+j)->grade = 0;
            scanf("%d",&answers);
            for (int k=0;k<answers;k++)
            {
                scanf("%d",&temp);
                (pdata+j)->grade += *(pgrade+temp-1);
            }
        }
        qsort(pdata,N,sizeof(Data),cmp);
        for (int j=0;j<N;j++)
        {
            if((pdata+j)->grade >= G) count++;
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
        for (int j=0;j<count;j++)
        {
            printf("%s %d\n",(pdata+j)->stuid,(pdata+j)->grade);
        }
    }


    return 0;
}


int
cmp(const void* a,const void* b)
{
    Data *pa = (Data*)a;
    Data *pb = (Data*)b;

    if (pa->grade < pb->grade) return 1;
    else if (pa->grade == pb->grade)
    {
        if (atoi(pa->stuid) > atoi(pb->stuid))
        {
            return 1;
        }
    }
    return -1;
}
