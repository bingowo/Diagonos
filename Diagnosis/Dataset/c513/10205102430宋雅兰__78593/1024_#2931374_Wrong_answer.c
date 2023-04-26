#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct student{
    char id[12];
    int g;
}stu;
int cmp(const void*p1,const void*p2)
{
    stu* a=(stu*)p1;
    stu* b=(stu*)p2;
    if(a->g==b->g)
    {
        return strcmp(a->id,b->id);
    }
    return b->g-a->g;
}
int main()
{
    int T,N,M,G;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0;
        int per[11];
        stu* p[500];
        scanf("%d%d%d",&N,&M,&G);
        for(int k=1;k<=M;k++)
        scanf("%d",per+k);
        for(int j=0;j<N;j++)
        {
            int m,t=0;
            p[j]=(stu*)malloc(sizeof(stu));
            p[j]->g=0;
            scanf("%s",p[j]->id);
            scanf("%d",&m);
            for(int k=0;k<m;k++)
            {
                scanf("%d",&t);
                p[j]->g+=per[t];
            }
            if(p[j]->g>=G)n++;
        }
        qsort(p,N,sizeof(stu*),cmp);
        printf("case #%d:\n%d\n",i,n);
        for(int k=0;k<n;k++)
        {
            printf("%s %d\n",p[k]->id,p[k]->g);
        }
        for(int j=0;j<N;j++)free(p[j]);
    }
    return 0;
}