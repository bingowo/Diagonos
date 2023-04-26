#include <stdio.h>
#include <stdlib.h>
//#define mask 1

struct data{
    long long a;
    int num_1;//1的个数
};

int cmp(struct data *a,struct data *b){
    struct data d1,d2;
    d1=*(a);d2=*(b);
    if(d2.num_1 != d1.num_1) return d2.num_1 - d1.num_1;
    else return d1.a-d2.a;
}

int main() {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case %d:\n",i);
        int N;
        long long mask=1;
        scanf("%d",&N);
        struct data num[N];
        for(int j=0;j<N;j++){
            scanf("%lld",&num[j].a);
            num[j].num_1=0;
            for(int t=0;t<64;t++){
                if(num[t].a & mask) num[t].num_1++;
                mask=mask<<1;
            }
        }
        qsort(num,N,sizeof(num[0]),cmp);
        for(int j=0;j<N;j++) printf("%lld%c",num[j].a,(j==N-1?'\n':' '));
    }
    return 0;
}
