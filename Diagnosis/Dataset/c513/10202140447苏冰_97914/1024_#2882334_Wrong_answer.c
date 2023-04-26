#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct STU
{
    char c[20];
    int cnt;
    int score;
}stu;
int cmp(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if(a->score!=b->score)
    {
        return ((a->score)>(b->score)?-1:1);
    }
    else
    {
        return (atoi(a->c)>atoi(b->c)?1:-1);
    }
}
int main()
{
    int T,x;
    scanf("%d",&T);
    int a[20];
    for(int i=0;i<T;i++)
    {
        int n,m,g,number=0;
        scanf("%d %d %d",&n,&m,&g);
        stu s[n];
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%s",s[j].c);
            scanf("%d",&s[j].cnt);
            s[j].score=0;
            for(int k=1;k<=s[j].cnt;k++)
            {
                scanf("%d",&x);
                s[j].score+=a[x];
            }
            if(s[j].score>=g) number++;
        }
        qsort(s,n,sizeof(stu),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",number);
        for(int j=0;j<n;j++)
        {
            if(s[j].score>=g)
            {
                printf("%s %d\n",s[j].c,s[j].score);
            }
        }
    }
    return 0;
}

