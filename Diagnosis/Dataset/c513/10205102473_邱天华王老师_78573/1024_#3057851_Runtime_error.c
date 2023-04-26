#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student
{
    char num[12];
    int q;
    int point;
}stu;
int cmp(const void* q1,const void* q2)
{
    stu* p1=(stu*)q1;
    stu* p2=(stu*)q2;
    if(p1->point!=p2->point)
    {
        return (p2->point-p1->point);
    }
    else 
        return strcmp(p2->num,p1->num);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int t1=0;t1<t;t1++)
    {
        int n,m,g;  
        stu stt[n];
        int gnum=0;      
        scanf("%d %d %d",&n,&m,&g);
        int score[m];
        int qnum=0;
        for(int i=0;i<m;i++)
            scanf("%d",score[i]);
        for(int j=0;j<n;j++)
        {
            scanf("%s %d",stt[j].num,stt[j].q);
            stt[j].point=0;
            for(int k=0;k<stt[j].q;k++)
            {
                scanf("%d",&qnum);
                stt[j].point+=score[qnum];
            }
        }
        qsort(stt,n,sizeof(stu),cmp);
        printf("case #%d:\n",t1);
        for(int a=0;a<n;a++)
        {
            if(stt[a].point>=g)
                gnum++;
        }
        printf("%d\n",gnum);
        for(int a0=0;a0<n;a0++)
        {
            if(stt[a0].point>=g)
            printf("%s %d\n",stt[a0].num,stt[a0].point);
        }
    }
    return 0;

}