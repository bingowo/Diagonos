#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct bigint
{
    int cnt;
    int v[1002];
    int f;
};

struct bigint int2big(int a,int flag)
{
    struct bigint R = {0,{0},flag};
    do
    {
        R.v[R.cnt++] = a%10;
        a/=10;
    }while(i>=0);
    return R;
}

struct bigint minus(struct bigint S,struct bigint T)
{
    struct bigint R = {0,{0},1};
    int k = 0,flag = 1;
    if(S.cnt > T.cnt) flag = 1;
    else if(S.cnt < T.cnt) flag = -1;
    //如果位数相同
    else if(S.cnt == T.cnt){
        int k = S.cnt;
        for(k;k>=0;k--){
            if(S.v[k] != T.v[k]){
                flag = S.v[k]>T.v[k]?1:-1;
                break;
            }
            }
        }
    if(flag == 1){
        while(k<S.cnt || k < T.cnt){
            S.v[i] = S.v[i]>=T.v[i]?S.v[i]-T.v[i]:S.v[i]-T.v[i]+10*(S.v[i+1]-(--S.v[i+1]));
            k++;
        }
        while(S.v[S.cnt-1]==0 && S.cnt>1) S.cnt--;
        S.flag = 1;
        return S;
    }
    else{
        while(k<S.cnt || k < T.cnt){
            T.v[i] = T.v[i]>=S.v[i]?T.v[i]-S.v[i]:T.v[i]-S.v[i]+10*(T.v[i+1]-(--T.v[i+1]));
            k++;
        }
        while(T.v[T.cnt-1]==0 && T.cnt>1) T.cnt--;
        T.flag = 1;
        return T;
    }
}

void transform(char *s1,BigInt *a){
    a->cnt=strlen(s1);
    for(int i=a->cnt-1;i>=0;i--){a->v[i]=*s1-'0';s1++;}
}

int main()
{
    char a[1001],b[1001];
    while(scanf("%s%s",a,b) !=EOF){
        struct bigint A = {0,{0},1},*A1;
        struct bigint B = {0,{0},1},*B1;
        *A1 = &A;
        *B1 = &B;
        transform(A1,A);
        transform(B1,B);
        A = minus(A,B);
        if(A.flag == 1)printf("-");
        for(int i=A.cnt-1;i>=0;i--){
            printf("%d",A.v[i]);
        }
        printf("\n");
    }
}

