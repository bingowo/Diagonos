#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    int count,score;
    char num[12];
}stu;

int cmp(const void*a,const void*b)
{
    stu a0=*(stu*)a,b0=*(stu*)b;
    if(a0.score!=b0.score) return b0.score-a0.score;
    else return strcmp(a0.num,b0.num);
}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,m,g,ans=0;scanf("%d%d%d",&n,&m,&g);
        stu p[n];int point[m];
        for(int t=0;t<m;t++) scanf("%d",&point[t]);
        for(int t=0;t<n;t++)
        {
            p[t].score=0;
            scanf("%s%d",p[t].num,&p[t].count);
            for(int q=0;q<p[t].count;q++)
            {
                int d;scanf("%d",&d);
                p[t].score+=point[d-1];
            }
            if(p[t].score>=g) ans++;
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n%d\n",i,ans);
        for(int t=0;t<ans;t++) printf("%s %d\n",p[t].num,p[t].score);
    }

    return 0;
}