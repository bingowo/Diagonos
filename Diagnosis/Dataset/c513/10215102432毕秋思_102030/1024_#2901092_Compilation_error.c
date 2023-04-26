#include<stdio.h>
#include<string.h>

struct Stu
{
    char snum[100];
    long long num;
    long long score;
    Stu()
    {
        score=0;
        num=0;
        for(int i=0;i<100;i++)
            snum[i]=0;
    }
    void ATOI()
    {
        for(int i=0;i<strlen(snum);i++)
        {
            int temp=snum[i]-'0';
            num*=10;
            num+=temp;
        }
    }
};

int cmp(const void *q1,const void *q2)
{
    Stu *p1=(Stu*)q1;
    Stu *p2=(Stu*)q2;
    if(p1->score==p2->score)
    {
        if(p1->num>p2->score) return 1;
        else return -1;
    }
    if(p2->score<p1->score) return -1;
    else if(p2->score>p1->score) return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,m,g;
        scanf("%d%d%d",&n,&m,&g);
        long long Qscore[10];
        for(int i=0;i<m;i++)
        {
            scanf("%lld",&Qscore[i]);
        }
        Stu *s=new Stu[n];
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i].snum;)
            s[i].ATOI();
            int slove;
            scanf("%d",&slove);
            for(int j=0;j<slove;j++)
            {
                int temp;
                scanf("%d",&temp);
                s[i].score+=Qscore[temp-1];
            }
        }
        qsort(s,n,sizeof(Stu),cmp);
        printf("case #%d:\n",i);
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(s[i].score>=g) flag++;
        }
        printf("%d\n",flag);
        for(int i=0;i<flag;i++)
            printf("%s %d\n",s[i].snum,s[i].score);
    }
    return 0;
}
