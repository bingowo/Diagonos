#include <stdio.h>
#define N 95

typedef struct {int cnt,v[N];} BIGINT;

BIGINT int2BIG(int x){
    BIGINT R={0,{0}};
    do{
        R.v[R.cnt++]=x%10;
        x=x/10;
    } while (x>0);
    return R;
}

BIGINT mul(BIGINT S, BIGINT T){
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++){
        int carry=0;
        int t,j,k;
        for( j=0;j<S.cnt;j++){
            t=T.v[i]*S.v[j]+carry+S.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0){
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;
    return R;
}

BIGINT pow(BIGINT a, int n){
    BIGINT r;
    if(n==0) return int2BIG(1);
    if(n==1) return a;
    r= pow(a,n/2);
    r=mul(r,r);
    if(n%2) r= mul(r,a);
    return r;
}

int main() {
    int times;
    scanf("%d",&times);
    for(int T=0;T<times;T++){
        int a,n;
        scanf("%d%d",&a,&n);
        printf("case #%d:\n",T);
        if(n==0) { printf("1"); continue;}
        if(n==1) { printf("%d",a); continue;}
        BIGINT r;
        r= int2BIG(a);
        r= pow(r,n);
        for(;r.cnt>=0;r.cnt--){
            printf("%d",r.v[r.cnt]);
            printf("\n");
        }

    }
    return 0;
}