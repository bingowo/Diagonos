#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student
{
    long long num;
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
        return (p2->num,p1->num);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int t1=0;t1<t;t1++)
    {
        int n,m,g;
        int solve;  
        stu stt[500];
        int gnum=0;      
        scanf("%d %d %d",&n,&m,&g);
        int score[10];
        int qnum=0;
        for(int i=0;i<m;i++)
            scanf("%d",score[i]);
        for(int j=0;j<n;j++)
        {
            scanf("%lld %d",stt[j].num,solve);
            stt[j].point=0;
            for(int k=0;k<solve;k++)
            {
                int tmp;
                scanf("%d",&tmp);
                stt[j].point+=score[tmp-1];
            }
        }
        qsort(stt,n,sizeof(stu),cmp);
        /*for(int aj=0;aj<n;aj++)
        {
            printf("%s %d",stt[aj].num,stt[aj].point);
        }*/
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
            printf("%lld %d\n",stt[a0].num,stt[a0].point);
        }
    }
    return 0;

}