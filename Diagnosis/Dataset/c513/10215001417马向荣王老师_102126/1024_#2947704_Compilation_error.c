#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int score;
    char id[12];
}Student;
int main()
{
    int t=0;
    scanf("%d\n",&t);//问题数
    for(int i=0;i<t;i++)
    {
        int n,m,g;
        scanf("%d %d %d\n",&n,&m,&g);//人数、考题数、分数线
        int num[11];
        for(int j=1;j<=m;j++)
        {
            scanf("%d ",&num[j]);//题号对应分值放进去
        }
        Student student[500];
        for(int j=0;j<n;j++)
        {
            int s;
            student[j].score=0;
            scanf("%s %d ",&student[j].id,&s);
            for(int k=0;k<s;k++)
            {
                int solve=0;
                scanf("%d ",&solve);
                student[j].score+=num[solve];
            }
        }
        qsort(student,n,sizeof(student[0]),cmp);
        int p=0;
        while(student[p].score>=g)
        {
            p++;
        }
        printf("case #%d:\n%d\n",i,p);
        for(int j=0;j<p;j++)
        {
            printf("%s %d\n",student[j].id,student[j].score);
        }
    }
    return 0;
}