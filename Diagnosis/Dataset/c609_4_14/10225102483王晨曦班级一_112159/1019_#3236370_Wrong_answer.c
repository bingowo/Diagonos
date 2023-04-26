#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ke
{
    int a;
    int c;
}keda[100000];

int cmp(const void *q1,const void *q2)
{
    struct ke *p1=(struct ke *)q1;
    struct ke *p2=(struct ke *)q2;

    if(p1->c >= p2->c) return -1;
    else if(p1->c < p2->c) return 1;

    if(p1->a > p2->a) return 1;
    else if(p1->a <= p2->a) return -1;
}

int count(int n)
{
    int cnt=0;
    while(n!=0)
    {
        n/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    int a[100000],i=0;
    while(scanf("%d",&a[i])!=EOF) i++;

    int cnt[100000];
    for(int j=0;j<i;j++)
        cnt[j]=count(a[j]);

    for(int k=0;k<i;k++)
    {
        keda[k].a=a[k];
        keda[k].c=cnt[k];
    }

    qsort(keda,i,sizeof(struct ke),cmp);

    for(int h=0;h<i-1;h++)
        printf("%d ",keda[h].a);
    printf("%d",keda[i-1].a);

    return 0;
}