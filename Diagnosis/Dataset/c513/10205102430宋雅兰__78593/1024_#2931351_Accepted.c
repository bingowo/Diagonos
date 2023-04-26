#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct student
{
    char ID[12];
    int g;
} STU;
int cmp(const void *p1, const void *p2)
{
    STU* a=(STU*) p1;
    STU* b=(STU*) p2;
    if(a->g==b->g)
    {
        for(int i=0; i<11; i++)
        {
            if(a->ID[i]==b->ID[i])continue;
            return (int)a->ID[i]-b->ID[i];
        }}
    return (b->g)-(a->g) ;//降序
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int N,M,G,j,r=0;
        scanf("%d%d%d",&N,&M,&G);
        int exam[M+1];
        for(j=1; j<=M; j++) //题号即下标
            scanf("%d",exam+j);
        STU stu[N];
        int m;
        for(j=0; j<N; j++)
        {
            scanf("%s",(stu[j].ID));
            scanf("%d",&m);
            stu[j].g=0;
            int tg=0;
            for(int k=0; k<m; k++)
            {
                scanf("%d",&tg);
                stu[j].g+=exam[tg];
            }
            if(stu[j].g>=G)r++;
        }
        qsort(stu,N,sizeof(stu[0]),cmp);
        printf("case #%d:\n%d\n",i,r);
        for(j=0; j<r; j++)
            printf("%s %d\n",stu[j].ID,stu[j].g);
    }

    return 0;
}