#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Stu
{
    char snum[20];
    int num;
    int score;
}stu[500];

int cmp(const void *q1,const void *q2)
{
    struct Stu *p1=(struct Stu*)q1;
    struct Stu *p2=(struct Stu*)q2;
    if(p1->score<p2->score) return 1;
    else if(p1->score>p2->score) return -1;
    else if(p1->score==p2->score)
    {
        if(p1->num>p2->score) return 1;
        else return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n=0,m=0,g=0;
        scanf("%d%d%d",&n,&m,&g);

        int Qscore[20]={0};
        for(int i=0;i<m;i++)
        {
            scanf("%d",&Qscore[i]);
        }

        for(int i=0;i<n;i++)
        {
            scanf("%s",&stu[i].snum);
            int temp=0,ans=0;
            for(int j=0;j<strlen(stu[i].snum);j++)
            {
                temp=stu[i].snum-'0';
                ans*=10;
                ans+=temp;
            }
            stu[i].num=ans;

            int count=0;
            int sum=0;
            scanf("%d",&count);
            for(int j=0;j<count;j++)
            {
                int s=0;
                scanf("%d",&s);
                sum+=Qscore[s-1];
            }
            stu[i].score=sum;
        }

        qsort(stu,n,sizeof(struct Stu),cmp);

        printf("case #%d:\n",t);

        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(stu[i].score>=g) flag++;
        }
        printf("%d\n",flag);
        for(int i=0;i<flag;i++)
            printf("%s %d\n",stu[i].snum,stu[i].score);
    }
    return 0;
}
