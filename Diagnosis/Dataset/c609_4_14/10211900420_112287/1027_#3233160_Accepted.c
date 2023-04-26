#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int sco;
    char stu[20];
}student;
int cmp(const void *x,const void *y)
{
    student c=*(student*)x,d=*(student*)y;
    if(c.sco!=d.sco) return d.sco-c.sco;
    return strcmp(c.stu,d.stu);
}
int main()
{
    int quiz[11],S,N,M,G,T,i,j,qu;
    student st[501];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d %d",&N,&M,&G);
        for(j=0;j<M;j++)
        {
            scanf("%d",&quiz[j]);
        }
        for(j=0;j<N;j++)
        {
            scanf("%s",st[j].stu);
            st[j].sco=0;
            scanf("%d",&S);
            for(int k=0;k<S;k++)
            {
                scanf("%d",&qu);
                st[j].sco=st[j].sco+quiz[qu-1];
            }
        }
        qsort(st,N,sizeof(st[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
        {
            if(st[j].sco<G)
                break;
        }
        printf("%d\n",j);
        for(j=0;j<N;j++)
        {
            if(st[j].sco>=G)
                printf("%s %d\n",st[j].stu,st[j].sco);
        }
    }
    return 0;
}
