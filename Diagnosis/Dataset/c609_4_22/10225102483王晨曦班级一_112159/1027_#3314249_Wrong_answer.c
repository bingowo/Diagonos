#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long long id;//学号
    int ti;//题目总数
    int sum;//总分
    int ques[11];//题号
}exam;

int cmp(const void *q1,const void *q2)
{
    exam *p1=(exam *)q1;
    exam *p2=(exam *)q2;

    if(p1->sum>p2->sum) return -1;
    else if(p1->sum<p2->sum) return 1;

    if(p1->id<p2->id) return -1;
    else return 1;
}

int main()
{
    int T;
    scanf("%d\n",&T);//问题数

    for(int c=0; c<T; c++)
    {
        int n,m,g;//n学生人数m题目数g分数线
        scanf("%d %d %d\n",&n,&m,&g);

        int point[12];
        for(int i=1; i<m+1; i++)
            scanf("%d ",&point[i]);//每道题的分值

        exam student[501]={0};
        for(int j=0; j<n; j++)
        {
            char uid[16];    scanf("%s ",uid);
            student[j].id=atol(uid);

            scanf("%d ",&student[j].ti);
            for(int k=1;k<student[j].ti+1;k++)
                scanf("%d ",&student[j].ques[j]);
        }

        int cnt=0;
        for(int q=1;q<n+1;q++)
        {
            for(int p=1;p<student[q].ti+1;p++)
            {
                student[q].sum+=point[student[q].ques[p]];
            }
            if(student[q].sum>=g) cnt++;
        }

        qsort(student+1,n,sizeof(student[1]),cmp);

        printf("case #%d:\n",c);
        printf("%d\n",cnt);
        for(int k=1;k<=n;k++)
            printf("%lld %d\n",student[k].id,student[k].sum);
    }

    return 0;
}