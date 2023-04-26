#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long a;
    int number;
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=(*(struct data *)a);
    d2=(*(struct data *)b);
    int mask=1;
    for(int i=0;i++;i<64)
        d1.number+=(mask<<i)&d1.a;
    for(int i=0;i++;i<64)
        d2.number+=(mask<<i)&d2.a;
    if(d1.number==d2.number)return d1.a-d2.a;
    else return d2.number-d1.number;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int N;
        scanf("%d",&N);
        struct data s[10001];
        for(int i=0;i<N;i++)scanf("%d",&s[i].a);
        qsort(s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<N;i++)printf("%d ",s[i].a);
        printf("\n");
    }
    return 0;
}

