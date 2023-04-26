#include<stdio.h>
#include<stdlib.h>

typedef struct Adata
{
    long long int a;//存放整数
    int num;//存放1的数量
} data;

int cmp(const void *a,const void *b);

long long int comp(long long int n);

int count(long long int n);

int main()
{
    int t,n;
    int i,j;
    data p[10000];
    scanf("%d",&t);//t为问题个数
    for (i=0;i<t;i++){
        scanf("%d",&n);//n为当前问题数据个数
        for (j=0;j<n;j++){
            scanf("%lld",&p[j].a);
        }
        qsort(p,n,sizeof(p[0]),cmp);//排序
        printf("case #%d:\n",i);
        for (j=0;j<n;j++){
            printf("%lld ",p[j].a);
        }
    }
    return 0;
}

int cmp(const void *_a,const void *_b)
{
    data t1 = *((data*)_a);
    data t2 = *((data*)_b);
    long long int temp1,temp2;
    temp1=t1.a;
    temp2=t2.a;
    t1.a=comp(t1.a);
    t2.a=comp(t2.a);//取补码
    t1.num=count(t1.a);
    t2.num=count(t2.a);//统计补码中1的个数
    if (t2.num > t1.num){
        return 1;
    }
    else if (t2.num == t1.num && temp2<temp1){
        return 1;
    }
    else{
        return -1;
    }
}

long long int comp(long long int n)
{
    int i;
    long long int t=0;
    for (i=0;i<64;i++){
        t=t<<1;
        t++;
    }
    n=n^t;
    n++;
    return n;
}

int count(long long int n)
{
    int i;
    int t=1;
    int num=0;
    for (i=0;i<64;i++){
        if (n&t > 0)
            num++;
        t=t<<1;
    }
    return num;
}