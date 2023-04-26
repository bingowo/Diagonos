#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char id[12];
    int score;
};

int cmp(const void*a,const void*b);
int main()
{
    int T,i;
    int N,M,G,j;
    int k;
    int S;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d %d",&N,&M,&G);
        struct Student students[501];
        int title[11]={0};
        for(k=1;k<=M;k++)
            scanf("%d",&title[k]);
        for(j=0;j<N;j++)
        {
            students[j].score=0;
            scanf("%s %d",students[j].id,&S);
            for(k=0;k<S;k++)
            {
                int solve;
                scanf("%d",&solve);
                students[j].score+=title[solve];
            }
        }
        qsort(students,N,sizeof(students[0]),cmp);

        int passed=0;
        while(students[passed].score>=G)
            ++passed;
        printf("case #%d:\n%d\n",i,passed);

        for(k=0;k<passed;k++)
        {
            printf("%s %d\n",students[k].id,students[k].score);
        }
    }
    return 0;
}

int cmp(const void*a,const void*b)
{
    struct Student *c=(struct Student*)a;
    struct Student *d=(struct Student*)b;
    if(c->score!=d->score)
        return d->score - c->score;
    else
        return strcmp(c->id,d->id);
}
