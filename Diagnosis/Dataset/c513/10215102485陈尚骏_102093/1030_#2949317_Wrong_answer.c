#include <stdio.h>
#include <stdlib.h>
#include<string.h>

long long LLabs(long long x)
{
    if(x<0) x=-x;
    return x;
}
typedef struct{
    long long num;
    long long nabs;
    long long c;
}Srt;

int cmp(const void *a,const void *b)
{
    Srt *p1=(Srt*)a,*p2=(Srt*)b;
    if(p1->c==p2->c)
        return p1->num>p2->num?1:-1;
    return p1->c-p2->c;
}

int main()
{
    int T;
    int d=0;
    scanf("%d",&T);
    while(T--)
    {
        int N,i;
        scanf("%d",&N);
        Srt s[10001];
        for(i=0;i<N;i++)
        {
            scanf("%lld",&s[i].num);
            s[i].nabs=LLabs(s[i].num);
            long long p=s[i].nabs;
            while(1)
            {
                if(p<10)
                {
                    s[i].c=p;
                    break;
                }
                p/=10;
            }
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n%lld",d,s[0].num);
        for(i=1;i<N;i++)
            printf(" %lld",s[i].num);
        printf("\n");
        d++;
    }
}
