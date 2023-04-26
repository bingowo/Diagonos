#include <stdio.h>
#include <stdlib.h>

#define Maxnumber 10000
struct data{
    long long int n;
    int number;
};

int onenumber(long long int n){
    int number=0;
    int d=1;
    for(int i=0;i<64;i++){
        if(d&n)number++;
        d=d<<1;
    }
    return number;
}

int compar(const void*a,const void*b){
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d1.number==d2.number){
        if(d1.n>d2.n)return 1;
        else return -1;
    }else{
    return d2.number-d1.number;
    }
}



int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        struct data members[Maxnumber];
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            scanf("%lld",&members[j].n);
            members[j].number=onenumber(members[j].n);
        }
        qsort(members,N,sizeof(members[0]),compar);
        for(int j=0;j<N;j++)printf("%lld ",members[j].n);
        printf("\n");
    }

    return 0;
}


