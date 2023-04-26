#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char stunum[15];
    int sum;
}STUDENT;

int score[15]={0},G;

int cmp(const void* a, const void* b)
{
    STUDENT a0=*(STUDENT*)a;STUDENT b0=*(STUDENT*)b;
    if(a0.sum>=G && b0.sum>=G)
    {   
        if(a0.sum==b0.sum) return strcmp(a0.stunum,b0.stunum);
        else return b0.sum-a0.sum;
    }
    else if(a0.sum==b0.sum) return 0;
    else if(a0.sum<G) return -1;
    else return 1;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        int i,N,M;
        scanf("%d %d %d",&N,&M,&G);
        STUDENT stu[N];
        for(i=1;i<=M;i++) scanf("%d",&score[i]);
        for(i=0;i<N;i++)
        {
            int j,qnum;
            scanf("%s %d",&stu[i].stunum,&qnum);
            stu[i].sum=0;
            for(j=0;j<qnum;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                stu[i].sum+=score[tmp];
            }
        }
        qsort(stu,N,sizeof(stu[0]),cmp);
        printf("case #%d:\n",t);
        int cnt=0;
        for(i=0;i<N;i++) if(stu[i].sum>=G) cnt++;
        printf("%d\n",cnt);
        for(i=0;i<N;i++)
        {
            if(stu[i].sum>=G) printf("%s %d\n",stu[i].stunum,stu[i].sum);
        }
        t++;
    }
    return 0;
}