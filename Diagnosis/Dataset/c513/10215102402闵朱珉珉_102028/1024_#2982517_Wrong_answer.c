#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {char number[12];int S;int s[11];int score;} student;
student p[500];
int cmp(const void *a,const void *b)
{
    student *a1=(student *)a,*b1=(student *)b;
    if (a1->score!=b1->score) return b1->score-a1->score;
    else return strcmp(a1->number,b1->number);
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int M,N,G,q[12]={0};
        scanf("%d%d%d",&N,&M,&G);
        for (int j=0;j<M;j++)
            scanf("%d",&q[j+1]);
        student p[500]={};
        for (int j=0;j<N;j++)
        {
            p[j].score=0;
            scanf("%s",p[j].number);
            scanf("%d",&p[j].S);
            for (int k=0;k<p[j].S;k++)
            {
                scanf("%d",&p[j].s[k]);
                p[j].score+=q[p[j].s[k]];

            }
        }//in
        qsort(p,N,sizeof(p[0]),cmp);//sort
        int sum=0;
        while (p[sum++].score >= G)
        printf("case #%d:\n%d\n",i,sum);
        for (int j=0;j<sum;j++)
        {
            printf("%s %d\n",p[j].number,p[j].score);
        }//out
    }
    return 0;
}
