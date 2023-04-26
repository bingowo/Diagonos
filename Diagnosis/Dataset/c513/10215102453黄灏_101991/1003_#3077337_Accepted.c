#include <stdio.h>
#include <stdlib.h>
//#define mask 1

struct data{
    long long num;
    int ones;
};

int cmp(struct data *a,struct data *b){
    struct data d1,d2;
    d1=*(a),d2=*(b);
    if(d1.ones!=d2.ones) return d2.ones - d1.ones;
    else {
        if(d1.num < d2.num) return -1;
        else return 1;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    struct data p[100000];
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            scanf("%lld",&p[j].num);
            p[j].ones=0;
            long long int mask=1;
            for(int h=0;h<64;h++){
                if(p[j].num & mask) p[j].ones++;
                mask=mask<<1;
            }
        }
        qsort(p,N,sizeof(p[0]),cmp);
        for(int k=0;k<N;k++){
            printf("%lld%c",p[k].num,(k==N-1?'\n':' '));
        }
    }
    return 0;
}