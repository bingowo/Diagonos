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

struct bigint add(struct bigint a,struct bigint b){
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
    struct bigint dp[101]= {[0] = {0,{0}},[1] = {1,{1}},[2] = {2,{1}},[3] = {3,{2}}};
    scanf("%d %d",&k,&n);
    if(n <= 4){
        printf("%d",dp[n-1].v[0]);
    }
    else{
        //i的位置就是n的位置
        for(i = 3;i<=n;i++){
            for(j = i-k;j<i-1;j+=2){
                dp[i] = add(dp[j], dp[i]);
            }
        }
    }
    for(int m = dp[n].cnt-1;m >=0;m--){
        printf("%d",dp[n].v[m]);
        //printf("hel\n");
    }
}
