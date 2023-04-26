#include <stdio.h>
#include <stdlib.h>

struct bigint
{
    int cnt;
    int v[1002];
};

struct bigint int2big(int x)
{
    struct bigint R = {0,{0}};
    do
    {
        R.v[R.cnt++] = x%10;
        x/=10;
    }while(x>0);
    return R;
}

struct bigint minus(struct bigint S,struct bigint T)
{
    struct bigint R = {0,{0}};
    int i;
    for(i = 0;i<S.cnt&&i<T.cnt;i++){
        if(S.v[i] < T.v[i]){
            S.v[i] += 10;
            S.v[i+1] -= 1;
        }
        R.v[i] = (S.v[i] - T.v[i]);
    }
    while(i<S.cnt){
        if(S.v[i]<0){
            S.v[i] += 10;
            S.v[i+1] -=1;
        }
        R.v[i] = S.v[i];
        i++;
    }
    while(i<T.cnt){
        R.v[i] = T.v[i];
        i++;
    }
    R.cnt = i;
    return R;
}

int main()
{
    int a,b;

    while(scanf("%d%d",&a,&b) !=EOF){
    struct bigint A = int2big(a);
    struct bigint B = int2big(b);
    struct bigint R;
    int x=1;
    if(a>b) {struct bigint R = minus(A,B);}
    if(a<b) {struct bigint R = minus(B,A);x=-1;}
    int i,flag = 0;
    for(i = R.cnt-1;i>=0;i--){
        if(R.v[i]!=0){flag = 1;}
        if(flag == 1) break;
    }
    if(a==b)printf("0");
    else{
    if(x == -1)printf("-");
    for(i;i>=0;i--){
        
        printf("%d",R.v[i]);
    }
    }
    printf("\n");
    }
}