#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 95

typedef struct{
    int cnt;
    int v[N];
}BIGINT;

BIGINT int2BIG(int x){
    BIGINT r={0,{0}};
    do{
        r.v[r.cnt++]=x%10;
        x/=10;
    }while(x>0);
    return r;
}

BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R={S.cnt+T.cnt,{0}};
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
        int a;
        scanf("%d",&a);
        //BIGINT A=int2BIG(a);
        BIGINT t=int2BIG(2);
        BIGINT res={1,{1}};
        for(int j=0;j<a;j++){
            res=mul(res,t);
        }
        for(int j=res.cnt-1;j>=0;j--){
            printf("%d\n",res.v[j]);
        }
    }
    return 0;
}
