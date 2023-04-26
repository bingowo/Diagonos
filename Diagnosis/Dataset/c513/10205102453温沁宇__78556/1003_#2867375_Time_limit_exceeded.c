#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long int a;  //整数
    int number;  //64位二进制补码表示中1的位数
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d2.number!=d1.number)
        return d2.number-d1.number;
    else{
        if(d1.a>d2.a) return 1;
        else return -1;
    }
}
int main()
{
    struct data p[10000];
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            scanf("%lld",&p[j].a);
            int d=1;p[j].number=0;
            for(int t=0;t<64;t++){
                if(p[j].a&d) p[j].number++;
                d=d<<1;
            }
        }
        qsort(p,N,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        int j;
        for(j=0;j=N-1;j++){
            printf("%lld",p[j].a);
        }
        printf("%lld\n",p[j].a);
    }
    return 0;
}
