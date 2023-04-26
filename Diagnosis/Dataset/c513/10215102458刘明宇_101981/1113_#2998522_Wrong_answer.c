#include <stdio.h>
#include <stdlib.h>

struct bigint
{
    int cnt;
    int v[1000];
};

struct bigint int2big(int x)
{
    struct bigint R = {0,{0}};
    do{
        R.v[R.cnt++] = x%10;
        x/=10;
    }while(x>0);
    return R;
}

struct bigint add(struct bigint a,struct bigint b)
{
    struct bigint R = {0,{0}};
    while(R.cnt < a.cnt && R.cnt <b.cnt){
        int carry = 0;
        R.v[R.cnt] = a.v[R.cnt] + b.v[R.cnt];
        carry = R.v[R.cnt]/10;
        R.v[R.cnt] = R.v[R.cnt]%10;
        R.cnt++;
        R.v[R.cnt] += carry;
    }
    while(R.cnt < a.cnt){
        R.v[R.cnt] = a.v[R.cnt];
        R.cnt++;
    }
    while(R.cnt < b.cnt){
        R.v[R.cnt] = b.v[R.cnt];
        R.cnt++;
    }
    if(R.v[R.cnt] == 0) R.cnt --;
    return R;
}


int main()
{
    int k,n,i,j;
    struct bigint dp[101]= {[0] = {0,{0}},[1] = {1,{1}},[2] = {2,{1}},[3] = {3,{2}}};
    scanf("%d %d",&k,&n);
    if(n <= 4){
        printf("%d",dp[n-1].v[0]);
    }
    else{
        //i的位置就是n的位置
        for(i = 4;i<=n;i++){
            for(j = i-k;j<i;j++){
                dp[i] = add(dp[j], dp[j+1]);
                printf("hi\n");
            }
        }
    }
    for(int m = 0;m < dp[n].cnt-1;m++){
        printf("%d",dp[n].v[m]);
        //printf("hel\n");
    }

}