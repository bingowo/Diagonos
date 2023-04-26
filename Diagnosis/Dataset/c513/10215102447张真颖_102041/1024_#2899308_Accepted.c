#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[12];
    long int goal;
}STUDENT;

int cmp(const void*a,const void*b)
{
    STUDENT *pa=(STUDENT*)a,*pb=(STUDENT*)b;
    if(pa->goal>pb->goal) return -1;
    else if(pa->goal<pb->goal) return 1;
    else
    {
        for(int i=0;i<11;i++)
        {
            if(pa->s[i]>pb->s[i]) return 1;
            else if(pa->s[i]<pb->s[i]) return -1;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N=0,M=0,G=0,gs=0;
        int q[10]={};
        STUDENT stu[500]={};
        STUDENT gstu[500]={};
        scanf("%d%d%d",&N,&M,&G);
        for(int i=1;i<=M;i++)
            scanf("%d",&q[i]);
        for(int i=0;i<N;i++)
        {
            int S=0;
            scanf("%s%d",stu[i].s,&S);
            stu[i].goal=0;
            for(int j=0;j<S;j++)
            {
                int rq;
                scanf("%d",&rq);
                stu[i].goal+=q[rq];
            }
        }
        for(int i=0,j=0;i<N;i++)
        {
            if(stu[i].goal>=G)
            {
                gstu[j].goal=stu[i].goal;
                strcpy(gstu[j].s,stu[i].s);
                j++,gs++;
            }
        }
        qsort(gstu,gs,sizeof(gstu[0]),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",gs);
        for(int i=0;i<gs;i++)
            printf("%s %d\n",gstu[i].s,gstu[i].goal);
    }
    return 0;
}
