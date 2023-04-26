#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 1000000

typedef struct{
    int cnt;
    int v[L];
}bigint;

bigint int2big(int x)
{
    bigint r={0,{0}};
    do{
        r.v[r.cnt++]=x%10;
        x/=10;
    }while(x>0);
    return r;
}

bigint mul(bigint S,bigint T)
{
    bigint R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++){
        int t,k,j;
        int carry=0;
        for(j=0;j<S.cnt;j++){
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while(carry>0){
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if(R.v[S.cnt+T.cnt-1]==0)R.cnt--;
    return R;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);

        bigint res={1,{1}};
        for(int j=2;j<=n;j++){
            bigint t=int2big(j);
            res = mul(res,t);
        }
        int k=0;
        while(res.v[k]==0)k++;
        printf("%d\n",k);
    }
    return 0;
}
