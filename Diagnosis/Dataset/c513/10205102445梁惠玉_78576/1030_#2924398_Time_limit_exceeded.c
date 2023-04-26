#include <stdio.h>
#include <stdlib.h>

struct NUM{
    long long number;int highest;
};

void GETHIGHEST(struct NUM tag)
{
    long long temp=tag.number;
    if(temp<0)
    {
        temp=abs(temp);
    }
    while(temp>=0)
    {
        temp/=10;
    }
    tag.highest=temp;
    return;
}

int cmp(const void* a,const void* b)
{
    struct NUM* p1=(struct NUM*)a;
    struct NUM* p2=(struct NUM*)b;
    if(p1->highest>p2->highest)
    {
        return -1;
    }
    else if(p1->highest<p2->highest)
    {
        return 1;
    }
    else{
        if(p1->number>p2->number)
        {
            return 1;
        }
        else{
            return -1;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct NUM tag[N+1];
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
           scanf("%lld",&tag[j].number);
           GETHIGHEST(tag[j]);
        }
        qsort(tag,N,sizeof(tag[0]),cmp);
        for(int j=0;j<N-1;j++)
        {
            printf("%lld ",tag[j].number);
        }
        printf("%lld\n",tag[N-1].number);


    }
    return 0;
}