#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char num[20];//学号
    int s;//成绩
}STU;

int cmp(const void *a,const void *b)
{
    STU *pa=(STU*)a,*pb=(STU*)b;
    if(pa->s!=pb->s)  return pb->s-pa->s;
    else  return strcmp(pa->num,pb->num);
}
int main()
{
    int T,i,j,k,N,M,G,t,a,cnt;
    int score[20];
    STU stu[600];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        cnt=0;
        scanf("%d%d%d",&N,&M,&G);
        for(j=1;j<=M;j++)
        {
            scanf("%d",&score[j]);
        }
        for(j=0;j<N;j++)
        {
            stu[j].s=0;
            scanf("%s",stu[j].num);
            scanf("%d",&t);
            for(k=0;k<t;k++)
            {
                scanf("%d",&a);
                stu[j].s+=score[a];
            }
        }
        qsort(stu,N,sizeof(STU),cmp);
        while(stu[cnt].s>=G)  cnt++;
        printf("case #%d:\n%d\n",i,cnt);
        for(j=0;j<cnt;j++)
        {
            printf("%s %d\n",stu[j].num,stu[j].s);
        }
    }
    return 0;
}