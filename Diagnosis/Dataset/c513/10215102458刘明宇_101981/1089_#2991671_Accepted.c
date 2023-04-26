#include <stdio.h>
#include <stdlib.h>

struct bigint
{
    int cnt;
    int v[10000];
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

struct bigint mul(struct bigint S,struct bigint T)
{
    struct bigint R = {S.cnt + T.cnt,{0}};
    for(int i = 0;i<T.cnt;i++){
        int t,k,j;
        int carry = 0;
        for(j = 0;j<S.cnt;j++){
            t = S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j] = t%10;
            carry = t/10;
        }
        k = i+j;
        while(carry > 0){
            t =carry + R.v[k];
            R.v[k] = t%10;
            carry = t/10;
            k++;
        }
    }
    if(R.v[S.cnt+T.cnt-1] == 0) R.cnt--;
    return R;
}

struct bigint pow0(struct bigint a,int n)
{
    struct bigint r;
    if(n == 0) return int2big(1);
    if(n == 1) return a;
    r = pow0(a,n/2);
    r = mul(r,r);
    if(n%2) r = mul(r,a);
    return r;

}

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-- >0){
        int A,B,N;
        scanf("%d %d %d",&A,&B,&N);
        struct bigint res1 = int2big(A);
        struct bigint res2 = pow0(res1, B);
        printf("case #%d:\n",cnt);
        for(int i = N-1;i>=0;i--){
            printf("%d",res2.v[i]);
        }
        printf("\n");
        cnt++;
    }
}
