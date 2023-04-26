#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct STU
{
    int score;
    int win;
    int fail;
    int num;
}stu;
int cmp(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if(a->score!=b->score)
    {
        return ((a->score)>(b->score)?-1:1);
    }
    else if(a->win!=b->win)
    {
        return ((a->win)>(b->win)?-1:1);
    }
    else if((a->fail)!=(b->fail))
    {
        return ((a->fail)>(b->fail)?1:-1);
    }
    else
    {
        return ((a->num)>(b->num)?1:-1);
    }
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0 && m==0) continue;
        stu s[15]={0};
        for(int i=0;i<n;i++) s[i].num=i+1;
        int a,b,c;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                s[a-1].score+=3;s[a-1].win++;
                s[b-1].score-=1;s[b-1].fail++;
            }
            else if(c==-1)
            {
                s[b-1].score+=3;s[b-1].win++;
                s[a-1].score-=1;s[a-1].fail++;
            }
            else if(c==0)
            {
                s[a-1].score++;s[b-1].score++;
            }
        }
        qsort(s,n,sizeof(stu),cmp);
        for(int i=0;i<n-1;i++)
        {
            printf("%d ",s[i].num);
        }
        printf("%d\n",s[n-1].num);
    }
    return 0;
}

