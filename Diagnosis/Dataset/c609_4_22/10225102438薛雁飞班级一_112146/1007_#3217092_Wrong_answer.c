#include <stdio.h>
#include <stdlib.h>
struct data
{
    long long int x;
    int y;
};
int cmp(const void*a,const void*b)
{
    struct data d1,d2;
    d1=*(struct data*)a;
    d2=*(struct data*)b;
    if(d1.y==d2.y)return(d1.x-d2.x);
    else return(d2.y-d1.y);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int k=0;k<T;k++){
        struct data d[10000];
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            long long int m=1LL;
            scanf("%lld",&d[i].x);
            d[i].y=0;
            for(int n=0;n<128;n++){
                if(d[i].x&m)d[i].y++;
                m=m<<1;
            }
        }
        qsort(d,N,sizeof(d[0]),cmp);
        printf("case #%d:\n",k);
        for(int i=0;i<N;i++)
            printf("%lld ",d[i].x);
        printf("\n");
    }

    return 0;
}
