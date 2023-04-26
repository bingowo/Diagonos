#include <stdio.h>
#include <stdlib.h>

typedef struct bigint
{
    int cnt;
    int v[1000];
} bigint;

bigint int2big(int x)
{
    bigint R = {0,{0}};
    do{
        R.v[R.cnt++] = x%10;
        x/=10;
    }while(x>0);
    return R;
}

bigint add(bigint a,bigint b){
    int i=0;
    while(i<a.cnt||i<b.cnt){
        a.v[i]+=b.v[i];
        a.v[i+1]+=a.v[i]/10;
        a.v[i]%=10;
        i++;
    }
    a.cnt=i+1;
    while(a.v[a.cnt-1]==0)a.cnt--;
    return a;
}


int main()
{
    int k,n,i,j;
    bigint dp[200]= {int2big(0)};
    scanf("%d %d",&k,&n);
    dp[12] = int2big(1);
    n = n + 10;
        //i的位置就是n的位置
        for(i = 13;i<=n;i++){
            for(j = i-k;j<i-1;j+=2){
                dp[i] = add(dp[j], dp[i]);
            }
        }
    if(dp[n].cnt == 0) printf("0");
    else{
    for(int m = dp[n].cnt-1;m >=0;m--){
        printf("%d",dp[n].v[m]);
        //printf("hel\n");
    }
    }
}

