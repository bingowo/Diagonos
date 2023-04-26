#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long a;
    long long b;
}NUM;

int cmp(const void *x,const void *y){
    long long X=((NUM*)x)->b;
    long long Y=((NUM*)y)->b;
    if (X>Y){
        return -1;
    }else if(X<Y){
        return 1;
    }else{
        if(((NUM*)x)->a>((NUM*)y)->a){
            return 1;
        }else{
            return -1;
        }
    }


}

int main()
{
    int T;//问题数量
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;//每个问题中的个数
        scanf("%d",&N);
        NUM *c=(NUM*)malloc(N*sizeof(NUM));
        for(int j=0;j<N;j++){
            scanf("%lld",&c[j].a);
            c[j].b=0;
            long long d;
            d=c[j].a;
            while(d){
                d=d&(d-1);
                c[j].b++;
            }
        }
        qsort(c,N,sizeof(NUM),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++){
            printf("%lld ",c[k].a);
        }
        printf("\n");
    }


    return 0;
}

