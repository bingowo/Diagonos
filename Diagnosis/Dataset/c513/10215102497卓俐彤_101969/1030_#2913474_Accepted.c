#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct number{
    long long int top;
    long long int num;
};

int compar(const void*a,const void*b){
    struct number d1,d2;
    d1=*((struct number*)a);
    d2=*((struct number*)b);
    if(d1.top==d2.top){
        if(d1.num>d2.num)return 1;
        else return -1;
    }
    else{
        if(d1.top>d2.top)return -1;
        else return 1;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int N;
        scanf("%d",&N);
        struct number numbers[N];
        for(int n=0;n<N;n++){
            numbers[n].num=0;
            numbers[n].top=0;
            scanf("%lld",&numbers[n].num);
            numbers[n].top=numbers[n].num;
            if(numbers[n].top<0)numbers[n].top*=(-1);
        }
        for(int n=0;n<N;n++){
            while(numbers[n].top/10)numbers[n].top/=10;
        }
        qsort(numbers, N, sizeof(numbers[0]), compar);
        for(int n=0;n<N;n++){
            if(n!=N-1)printf("%lld ",numbers[n].num);
            else printf("%lld\n",numbers[n].num);
        }
    }
    return 0;
}
