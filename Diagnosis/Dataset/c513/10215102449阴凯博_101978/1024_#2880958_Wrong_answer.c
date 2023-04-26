#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char number[10000];
    int grade;
} STUDENT;

int cmp1(const void *a,const void *b)
{
    STUDENT* pa=(STUDENT*)a;
    STUDENT* pb=(STUDENT*)b;
    if (pa->grade>pb->grade) return -1;
    else if ((pa->grade<pb->grade)) return 1;
    else
    {
         return (strcmp(pa->number,pb->number)?1:-1);
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    int N,M,G,S,num;  int j,k;
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d %d %d",&N,&M,&G);
        int* arr=(int*)malloc(M*sizeof(int));
        STUDENT* cls=(STUDENT*)calloc(N,sizeof(STUDENT));
        for (j=0;j<M;j++)
            scanf("%d",&arr[j]);
        for (j=0;j<N;j++)
        {
            scanf("%s",cls[j].number);
            scanf("%d",&S);
            for (k=0;k<S;k++)
            {
                scanf("%d",&num);
                cls[j].grade+=arr[num-1];
            }
        }

        qsort(cls,N,sizeof(STUDENT),cmp1);
        for (j=0;j<N;j++)
        {
            if (cls[j].grade<G) break;
            printf("%s %d\n",cls[j].number,cls[j].grade);
        }
        free(arr); free(cls);
    }

    return 0;
}
