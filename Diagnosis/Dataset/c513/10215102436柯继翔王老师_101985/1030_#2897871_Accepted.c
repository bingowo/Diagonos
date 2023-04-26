#include <stdio.h>
#include <stdlib.h>

struct sortInt{
    long long x;
    int y;
};

int cmp(const void *a,const void *b){
    struct sortInt *a1 = (struct sortInt*)a;
    struct sortInt *b1 = (struct sortInt*)b;
    if(a1->y == b1->y){
        return a1->x > b1->x?1:-1;
    }else{
        return a1->y > b1->y?-1:1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int N;
        scanf("%d",&N);
        struct sortInt a[10001];
        for(int j = 0;j < N;j++){
            scanf("%ld",&a[j].x);
            long long n = labs(a[j].x);
            int m = 0;
            while(n != 0){
                m = n % 10;
                n /= 10;
            }
            a[j].y = m;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < N - 1;j++){
            printf("%ld ",a[j].x);
        }
        printf("%ld\n",a[N - 1].x);
    }
    return 0;
}
