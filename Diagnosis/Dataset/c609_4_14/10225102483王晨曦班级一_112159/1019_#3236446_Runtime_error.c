#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LL long long int

struct ke
{
    LL a;
    LL c;
}keda[100000];

int cmp(const void *q1,const void *q2)
{
    struct ke *p1=(struct ke *)q1;
    struct ke *p2=(struct ke *)q2;

    if(p1->c > p2->c) return -1;
    else if(p1->c < p2->c) return 1;

    if(p1->a <= p2->a) return -1;
    else if(p1->a > p2->a) return 1;
}

LL count(LL n)
{
    LL cnt=0;
    if(n==0) cnt=1;
    while(n!=0)
    {
        n/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    LL i=0;
    while(scanf("%lld",&keda[i].a)!=EOF) i++;

    for(LL j=0;j<i;j++)
        keda[j].c=count(keda[j].a);


    qsort(keda,i,sizeof(struct ke),cmp);

    for(LL h=0;h<i-1;h++)
        printf("%lld ",keda[h].a);
    printf("%lld",keda[i-1].a);

    return 0;
}