# include <stdio.h>
# include <stdlib.h>

int cmp(const void *a,const void*b);
void solve();

struct data {
    long long int num;
    int num1;
};

int main(){
    int T;
    scanf("%d",&T);
    for(int t = 0; t<T; t++){
        printf("case #%d:\n",t);
        solve();
    }
}

void solve(){
    int N;
    struct data s[10000];
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%lld",&s[i].num);
        long long int mask = 1;
        s[i].num1 = 0;
        for(int j = 0; j < 64; j++){
            if((mask & s[i].num) != 0){
                s[i].num1++;
            }
            mask = mask<<1;
        }
    }
    qsort(s,N,sizeof(s[0]),cmp);
    for(int k=0; k<N; k++){
        printf("%lld%c",s[k].num,(k==N-1?'\n':' '));
    }
}

int cmp(const void *a,const void*b){
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d1.num1 != d2.num1){
        return d2.num1 -d1.num1;
    }
    else{
        if(d1.num > d2.num){
            return 1;
        }else{
            return -1;
        }
    }
}
