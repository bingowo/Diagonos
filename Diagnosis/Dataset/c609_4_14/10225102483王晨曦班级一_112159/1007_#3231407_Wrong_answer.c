#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct bin
{
    int data;//对应的1的数量
    long long num;//输入的数据
};


int cmp(const void *q1, const void *q2)//排序
{
    struct bin *p1 = (struct bin *)q1;
    struct bin *p2 = (struct bin *)q2;

    if(p1->data > p2->data) return -1;
    else if(p1->data <= p2->data)return 1;

    if(p1->num > p2->num) return 1;
    if(p1->num < p2->num) return -1;


}

int getdata(long long int a)//获取二进制中1的位数
{
    int data=0;
    for(int i=0;i<64;i++)
    {
        if((a&((long long int)1<<i))==(1LL<<i))
            data++;
    }
    return data;
}

int main()
{
    int T; scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        int N; scanf("%d",&N);
        struct bin s[10010];

        for(int j=0;j<N;j++)
        {
            scanf("%lld",&s[j].num);
            long long int temp=s[j].num;
            s[j].data=getdata(temp);
        }

        qsort(s,N,sizeof(struct bin),cmp);
        printf("case #%d:\n",i);

        for(int j=0;j<N-1;j++)
            printf("%lld ",s[j].num);

        printf("%lld\n",s[N-1].num);
    }
    return 0;
}



