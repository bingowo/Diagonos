#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STU
{
    char num[11];
    int cnt;
    int s[11];
    int sum;
} stu;
int cmp(const void* x,const void*y)
{
    stu* a=(stu*)x;
    stu* b=(stu*)y;
    if(a->sum!=b->sum) return b->sum-a->sum;
    else return strcmp(a->num,b->num);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int N,M,G;
        scanf("%d %d %d\n",&N,&M,&G);
        int a[M+1];
        for(int j=0; j<M; j++)
        {
            scanf("%d ",&a[j]);
        }
        stu m[N+1];
        for(int k=0; k<N; k++)
        {
            scanf("%s %d ",&m[k].num,&m[k].cnt);
            for(int l=0; l<m[k].cnt; l++) scanf("%d",&m[k].s[l]);
            m[k].sum+=a[m[k].s[l]];
        }
        qsort(m,N,sizeof(stu),cmp);
        int h=0;
        for(int n=0; n<N; n++)
        {
            if(m[n].sum>=G) h++;
        }
        stu p[h+1];
        int q=0;
        for(int n=0; n<N; n++)
        {
            if(m[n].sum>=G) p[q++]=m[n];
        }
        printf("case #%d:\n",i);
        printf("%d\n",h);
        for(int q=0; q<h; q++) printf("%s %d\n",p[q].num,p[q].sum);
    }

    return 0;
}
