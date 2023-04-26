#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000

struct keda
{
    int cnt;//数据的位数
    int num;//输入的数据
};


int cmp(const void *q1,const void *q2)
{
    struct keda *p1 = (struct keda *)q1;
    struct keda *p2 = (struct keda *)q2;

    if(p1->cnt >= p2->cnt) return -1;
    else if(p1->cnt < p2->cnt) return 1;

    if(p1->num <= p2->num) return -1;
    else if(p1->num > p2->num) return 1;
}

int count(int a)
{
    int cnt=0;
    if(a<0) a=-a;
    while(a>=0)
    {
        a/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    int i=0;
    struct keda s[N];

    while(scanf("%d",&s[i].num)!=EOF)
    {
        s[i].cnt=count(s[i].num);
        i++;
    }

    qsort(s,i,sizeof(struct keda),cmp);

    for(int k=0;k<i-1;k++)
        printf("%d ",s[k].num);

    printf("%d\n",s[i-1].num);

    return 0;
}