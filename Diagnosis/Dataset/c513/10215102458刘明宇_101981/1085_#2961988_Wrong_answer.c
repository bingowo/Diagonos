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

struct bigint int2big(char x[])
{
    struct bigint R = {0,{0}};
    int i = strlen(x) - 1;
    do
    {
        R.v[R.cnt++] = x[i]-'0';
        i--;
    }while(i>=0);
    return R;
}

struct bigint minus(struct bigint S,struct bigint T)
{
    struct bigint R = {0,{0},1};
    int i,m,flag = 1;
    //如果位数相同
    if(S.cnt == T.cnt){
        int k = S.cnt-1;
        for(k;k>=0;k++){
            if(S.v[k] == T.v[k]) continue;
            else if(S.v[k] < T.v[k]){
                flag = -1;
                R.f = -1;
                break;
            }
            k--;
        }
    }
    if(S.cnt < T.cnt || flag == -1){
        R.f = -1;
        m = 0;
        while(m<T.cnt){
            if(T.v[m] < S.v[m]){
                R.v[m] = T.v[m] + 10 - S.v[m];
                T.v[m+1] -=1;
            }
            else{
                R.v[m] = T.v[m] - S.v[m];
            }
            m++;
        }
    }
    else if(S.cnt > T.cnt || flag == 1){
        m = 0;
        while(m<S.cnt){
        if(S.v[m] < T.v[m]){
            R.v[m] = S.v[m] + 10 - T.v[m];
            S.v[m+1] -=1;
        }
        else{
            R.v[m] = S.v[m] - T.v[m];
        }
        m++;
        }
    }
    R.cnt = m;
    return R;
}

int main()
{
    char a[501],b[501];

    while(scanf("%s%s",&a,&b) !=EOF){
        struct bigint A = int2big(a);
        struct bigint B = int2big(b);
        struct bigint R;
        int i,flag = 0;
        for(i = R.cnt-1;i>=0;i--){
            if(R.v[i]!=0){flag = 1;}
            if(flag == 1) break;
        }
        i++;
        if(R.f == -1)printf("-");
        for(i;i>=0;i--){
            printf("%d",R.v[i]);
        }
        printf("\n");
    }
}
