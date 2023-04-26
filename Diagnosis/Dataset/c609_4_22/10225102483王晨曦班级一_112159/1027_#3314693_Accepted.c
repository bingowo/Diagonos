#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char uid[20];
    long long id;
    int ti;
    int sum;
    int ques[20];
}exam;

int cmp(const void *q1,const void *q2)
{
    exam *p1=(exam *)q1;
    exam *p2=(exam *)q2;

    if(p1->sum!=p2->sum)
    {
        if(p1->sum>p2->sum) return -1;
        else if(p1->sum<p2->sum) return 1;
    }
    else
    {
        if(p1->id<=p2->id) return -1;
        else return 1;
    }
}

int main()
{
    int T;
    scanf("%d\n",&T);

    for(int c=0; c<T; c++)
    {
        exam student[501]={0};

        int n,m,g;
        scanf("%d %d %d\n",&n,&m,&g);

        int point[20];
        for(int i=1; i<m+1; i++)
            scanf("%d ",&point[i]);

        for(int j=1; j<n+1; j++)
        {
            scanf("%s",student[j].uid);
            student[j].id=atoll(student[j].uid);
            scanf("%d",&student[j].ti);
            for(int k=1;k<student[j].ti+1;k++)
                scanf("%d",&student[j].ques[k]);
        }

        int cnt=0;
        for(int q=1;q<n+1;q++)
        {
            for(int p=1;p<student[q].ti+1;p++)
                student[q].sum+=point[student[q].ques[p]];

            if(student[q].sum>=g) cnt++;
            else continue;
        }

        qsort(student+1,n,sizeof(student[1]),cmp);

        printf("case #%d:\n",c);
        printf("%d\n",cnt);
        for(int i=1;i<cnt+1;i++)
        {
            for(int j=0;j<strlen(student[i].uid);j++)
                printf("%d",student[i].uid[j]-'0');
            printf(" %d\n",student[i].sum);
        }

    }

    return 0;
}

