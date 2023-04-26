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

BIGINT pow(BIGINT a,int n){
    BIGINT r;
    if(n==0)return int2BIG(1);
    if(n==1)return a;
    r=pow(a,n/2);
    r=mul(r,r);
    if(n%2)r=mul(r,a);
    return r;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        BIGINT A=int2BIG(a);
        BIGINT B=pow(A,b);
        for(int j=B.cnt-1;j>=0;j--){
            printf("%d",B.v[j]);
        }
    }
    return 0;
}
