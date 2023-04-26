#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student
{
    char num[11];
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
        return (strcmp(p2->num,p1->num));
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
        long long score[10];
        int qnum=0;
        for(int i=0;i<m;i++)
            scanf("%d",score[i]); //输入每道题的分值
           
        for(int j=0;j<n;j++)
        {
            scanf("%s %d",stt[j].num,solve);  //solve是学生解决了的问题数目
            stt[j].point=0; //point学生分数
            for(int k=0;k<solve;k++)
            {
                int tmp; //tmp是解答出的题目的序号
                scanf("%d",&tmp);
                stt[j].point+=score[tmp-1];
            }
        }
        qsort(stt,n,sizeof(stu),cmp);
        /*for(int aj=0;aj<n;aj++)
        {
            printf("%s %d",stt[aj].num,stt[aj].point);
        }*/
        //printf("case #%d:\n",t1);
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