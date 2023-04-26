#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s1[100];
    int S;
    int s3[10];
    int score;
}ST;
int cmp(const void *p1,const void *p2)
{
    ST* a=p1;
    ST* b=p2;
    if((*a).score>(*b).score) return -1;
    else if((*a).score<(*b).score) return 1;
    else
    {
        return strcmp((*a).s1,(*b).s1);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    ST a[10];
    for(int i=0;i<T;i++)
    {
        int N,M,G;
        scanf("%d %d %d",&N,&M,&G);
        int num[11]={0};
        for(int j=0;j<M;j++)
        {
            scanf("%d",&num[j]);
        }
        for(int k=0;k<N;k++)
        {
            a[k].score=0;
            scanf("%s",a[k].s1);
            scanf("%d",&a[k].S);
            for(int l=0;l<a[k].S;l++)
            {
                scanf("%d",&a[k].s3[l]);
                a[k].score=a[k].score+num[a[k].s3[l]-1];
            }
        }
        qsort(a,N,sizeof(ST),cmp);
        int q;
        for(q=0;q<N;q++)
        {
            if(a[q].score<G) break;
        }
        printf("case #%d:\n%d\n",i,q);
        for(int w=0;w<q;w++)
        {
            printf("%s %d\n",a[w].s1,a[w].score);
        }
    }
}
