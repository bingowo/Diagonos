#include <stdio.h>
#include <stdlib.h>

typedef struct std{long long int number;int score;int teshu}Student;

int cmp(const void*a, const void*b)
{
    Student*p1=(Student*)a;
    Student*p2=(Student*)b;
    if(p1->score<p2->score)
    {
        return 1;
    }
    else if(p1->score>p2->score)
    {
        return -1;
    }
    else if(p1->score==p2->score&&p1->number<p2->number)
    {
        return -1;
    }
    else
        return 1;

}

int main()
{
    int N,M,G,ti,tihao;
    int count,count1;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        int K[10];
        int num=0;
        Student S[500];
        Student*p=S;
        scanf("%d %d %d",&N,&M,&G);
        for(int q=0;q<M;q++)
        {
            scanf("%d",&K[q]);
        }
        for(int i=0;i<N;i++)
        {
            int sum=0;
            scanf("%lld",&S[i].number);
            if(S[i].number<10000000000)
            {
                S[i].number+=10000000000;
                S[i].teshu=1;
            }
            scanf("%d",&ti);
            if(ti<=0)
            {
                S[0].score=0;
            }
            for(int j=0;j<ti;j++)
            {
                scanf("%d",&tihao);
                sum+=K[tihao-1];
                S[i].score=sum;
            }
        }
        qsort(p,N,sizeof(S[0]),cmp);
        printf("case #%d:\n",count1-count-1);
        for(int i=0;i<N;i++)
        {
            if(S[i].score>=G)
            {
                num++;
            }
        }
        printf("%d\n",num);
        for(int i=0;i<num;i++)
        {
            if(S[i].teshu==1)
            {
                printf("%lld %d\n",S[i].number-10000000000,S[i].score);
            }
            else
            printf("%lld %d\n",S[i].number,S[i].score);
        }
    }
}
