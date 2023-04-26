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
    }while(a>=0);
    return R;
}

struct bigint minus(struct bigint S,struct bigint T)
{
    int k = 0,flag = 1;
    if(S.cnt > T.cnt) flag = 1;
    else if(S.cnt < T.cnt) flag = -1;
    //如果位数相同
    else{
        int k = S.cnt;
        while(k>=0){
            if(S.v[k] != T.v[k]){
                flag = S.v[k]>T.v[k]?1:-1;
                break;
            }
            k--;
        }
    }
    if(flag == 1){
        while(k<S.cnt || k < T.cnt){
            S.v[k] = S.v[k]>=T.v[k]?S.v[k]-T.v[k]:S.v[k]-T.v[k]+10*(S.v[k+1]-(--S.v[k+1]));
            k++;
        }
        while(S.v[S.cnt-1]==0 && S.cnt>1) S.cnt--;
        S.f = 1;
        return S;
    }
    else{
        while(k<S.cnt || k < T.cnt){
            T.v[k] = T.v[k]>=S.v[k]?T.v[k]-S.v[k]:T.v[k]-S.v[k]+10*(T.v[k+1]-(--T.v[k+1]));
            k++;
        }
        while(T.v[T.cnt-1]==0 && T.cnt>1) T.cnt--;
        T.f = 1;
        return T;
    }
}

void transform(char *s1,struct bigint *a){
    a->cnt=strlen(s1);
    for(int i=a->cnt-1;i>=0;i--){a->v[i]=*s1-'0';s1++;}
}

int main()
{
    char a[1001],b[1001];
    while(scanf("%s%s",a,b) !=EOF){
        struct bigint A = {0,{0},1},*A1;
        struct bigint B = {0,{0},1},*B1;
        A1 = &A;
        B1 = &B;
        transform(a,A1);
        transform(b,B1);
        A = minus(A,B);
        if(A.f == -1)printf("-");
        for(int i=A.cnt-1;i>=0;i--){
            printf("%d",A.v[i]);
        }
        printf("\n");
    }
}

